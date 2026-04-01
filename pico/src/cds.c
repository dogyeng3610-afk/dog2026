#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"

// CDS (LDR) 입력 ADC 핀 (GPIO27 = ADC1)
#define CDS_GPIO 27
#define CDS_ADC_CHANNEL 1

// I2C LCD(PCF8574 백팩) 설정
#define I2C_PORT i2c0
#define I2C_SDA_PIN 4
#define I2C_SCL_PIN 5
#define I2C_BAUDRATE 100000
#define LCD_ADDR 0x27 // 안 되면 0x3F로 변경

#define LCD_RS 0x01
#define LCD_RW 0x02
#define LCD_EN 0x04
#define LCD_BL 0x08

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
    {
        sleep_ms(2);
    }
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
    {
        lcd_data(line[i]);
    }
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

int main()
{
    stdio_init_all();
    sleep_ms(2000);

    // LCD 초기화
    lcd_init_display();

    // ADC 초기화 (CDS: GPIO27 = ADC1)
    adc_init();
    adc_gpio_init(CDS_GPIO);
    adc_select_input(CDS_ADC_CHANNEL);

    char line1[17];
    char line2[17];

    while (true)
    {
        uint16_t raw = adc_read(); // 0 ~ 4095
        float voltage = raw * (3.3f / 4095.0f);

        // 밝을수록 큰 값이 되도록 비례값 계산
        float light_level = ((float)raw / 4095.0f) * 100.0f;

        snprintf(line1, sizeof(line1), "CDS raw=%4u", raw);
        snprintf(line2, sizeof(line2), "V=%.2f Lv=%.0f%%", voltage, light_level);

        lcd_print_line(0, line1);
        lcd_print_line(1, line2);

        printf("CDS: raw=%u, V=%.2f, level=%.0f%%\n", raw, voltage, light_level);

        sleep_ms(1000);
    }

    return 0;
}