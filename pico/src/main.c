#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/sync.h"

#define DHT_PIN 15

// I2C LCD(PCF8574 백팩) 설정
#define I2C_PORT i2c0
#define I2C_SDA_PIN 4
#define I2C_SCL_PIN 5
#define I2C_BAUDRATE 100000
#define LCD_ADDR 0x27 // 모듈 주소가 다르면 0x3F로 변경

#define LCD_RS 0x01
#define LCD_RW 0x02
#define LCD_EN 0x04
#define LCD_BL 0x08

//--------------------------------------
// I2C LCD 제어 함수
//--------------------------------------
static void lcd_i2c_write(uint8_t data)
{
    uint8_t buffer = data | LCD_BL;
    i2c_write_blocking(I2C_PORT, LCD_ADDR, &buffer, 1, false);
    sleep_us(50);
}

static void lcd_toggle_enable(uint8_t data)
{
    lcd_i2c_write(data | LCD_EN);
    sleep_us(1);
    lcd_i2c_write(data & ~LCD_EN);
    sleep_us(50);
}

static void lcd_send_nibble(uint8_t nibble, uint8_t mode)
{
    uint8_t data = (nibble & 0xF0) | mode;
    lcd_i2c_write(data);
    lcd_toggle_enable(data);
}

static void lcd_send_byte(uint8_t value, uint8_t mode)
{
    lcd_send_nibble(value & 0xF0, mode);
    lcd_send_nibble((value << 4) & 0xF0, mode);
}

static void lcd_command(uint8_t cmd)
{
    lcd_send_byte(cmd, 0);
    if (cmd == 0x01 || cmd == 0x02)
        sleep_ms(2);
}

static void lcd_data(uint8_t value)
{
    lcd_send_byte(value, LCD_RS);
}

static void lcd_clear(void)
{
    lcd_command(0x01);
}

static void lcd_set_cursor(uint8_t col, uint8_t row)
{
    static const uint8_t row_offsets[] = {0x00, 0x40};
    lcd_command(0x80 | (col + row_offsets[row % 2]));
}

static void lcd_print_line(uint8_t row, const char *text)
{
    char line[17];
    snprintf(line, sizeof(line), "%-16.16s", text);

    lcd_set_cursor(0, row);
    for (int i = 0; i < 16; i++)
        lcd_data(line[i]);
}

static void lcd_init_display(void)
{
    i2c_init(I2C_PORT, I2C_BAUDRATE);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

    sleep_ms(50);
    lcd_send_nibble(0x30, 0);
    sleep_ms(5);
    lcd_send_nibble(0x30, 0);
    sleep_us(150);
    lcd_send_nibble(0x30, 0);
    lcd_send_nibble(0x20, 0); // 4bit mode

    lcd_command(0x28); // 2 line, 5x8 font
    lcd_command(0x0C); // display on, cursor off
    lcd_command(0x06); // entry mode
    lcd_clear();
}

//--------------------------------------
// 타임아웃 기반 대기 함수
//--------------------------------------
bool wait_for_level(bool level, uint32_t timeout_us)
{
    uint32_t start = time_us_32();
    while (gpio_get(DHT_PIN) != level)
    {
        if (time_us_32() - start > timeout_us)
            return false;
    }
    return true;
}

//--------------------------------------
// DHT 읽기
//--------------------------------------
bool read_dht(float *temperature, float *humidity)
{
    uint8_t data[5] = {0};

    uint32_t irq_state = save_and_disable_interrupts();

    gpio_set_dir(DHT_PIN, GPIO_OUT);
    gpio_put(DHT_PIN, 0);
    sleep_ms(20);
    gpio_put(DHT_PIN, 1);
    sleep_us(30);
    gpio_set_dir(DHT_PIN, GPIO_IN);

    if (!wait_for_level(0, 100))
        goto fail;
    if (!wait_for_level(1, 100))
        goto fail;
    if (!wait_for_level(0, 100))
        goto fail;

    for (int i = 0; i < 40; i++)
    {
        if (!wait_for_level(1, 70))
            goto fail;

        sleep_us(30);

        if (gpio_get(DHT_PIN))
            data[i / 8] |= (1 << (7 - (i % 8)));

        if (!wait_for_level(0, 70))
            goto fail;
    }

    restore_interrupts(irq_state);

    if ((data[0] + data[1] + data[2] + data[3]) != data[4])
    {
        printf("[DHT] checksum fail (%u+%u+%u+%u!=%u)\n", data[0], data[1], data[2], data[3], data[4]);
        return false;
    }

    // DHT11: data[0]=습도 정수, data[1]=습도 소수( 항상 0 ), data[2]=온도 정수, data[3]=온도 소수( 항상 0 )
    *humidity = (float)data[0] + (float)data[1] / 10.0f;
    *temperature = (float)data[2] + (float)data[3] / 10.0f;

    printf("[DHT] raw=%u,%u,%u,%u,%u -> %.1f%% %.1fC\n", data[0], data[1], data[2], data[3], data[4], *humidity, *temperature);

    return true;

fail:
    restore_interrupts(irq_state);
    printf("[DHT] signal timeout fail\n");
    return false;
}

//--------------------------------------
// 메인
//--------------------------------------
int main()
{
    char line1[17];
    char line2[17];

    stdio_init_all();
    gpio_init(DHT_PIN);
    gpio_pull_up(DHT_PIN);
    lcd_init_display();

    lcd_print_line(0, "Sensor Booting");
    lcd_print_line(1, "Please wait...");

    printf("[SYSTEM] Boot complete\n");
    printf("[SYSTEM] DHT -> I2C LCD mode\n");

    while (1)
    {
        float temp = 0.0f;
        float humi = 0.0f;
        bool dht_ok = read_dht(&temp, &humi);

        if (dht_ok)
        {
            snprintf(line1, sizeof(line1), "T:%.1fC H:%2d.0%%", temp, (int)humi);
            snprintf(line2, sizeof(line2), " ");

            lcd_print_line(0, line1);
            lcd_print_line(1, line2);

            printf("[DATA] %s\n", line1);
        }
        else
        {
            lcd_print_line(0, "DHT read fail");
            lcd_print_line(1, "Check wiring");
            printf("[ERROR] DHT read fail\n");
        }

        sleep_ms(2000);
    }
}