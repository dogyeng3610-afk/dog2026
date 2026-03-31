#include <stdio.h>
#include "pico/stdlib.h"
// #include "hardware/adc.h"   // 조도센서 비활성화
#include "hardware/gpio.h"
#include "hardware/sync.h"

#define DHT_PIN 15
// #define LIGHT_ADC 0   // 조도센서 비활성화

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
        return false;

    *humidity = data[0];
    *temperature = data[2];

    return true;

fail:
    restore_interrupts(irq_state);
    return false;
}

//--------------------------------------
// 메인
//--------------------------------------
int main()
{
    stdio_init_all();

    gpio_init(DHT_PIN);

    // adc_init();                // 조도센서 비활성화
    // adc_gpio_init(26);
    // adc_select_input(LIGHT_ADC);

    printf("[SYSTEM] Boot complete\n");
    printf("[SYSTEM] DHT sensor only mode\n");

    while (1)
    {
        float temp = 0.0f, humi = 0.0f;

        bool dht_ok = read_dht(&temp, &humi);

        // uint16_t light = adc_read();  // 조도센서 비활성화

        if (dht_ok)
        {
            printf("[DATA] Temp: %.1f C | Humi: %.1f %%\n",
                   temp, humi);
        }
        else
        {
            printf("[ERROR] DHT read fail\n");
        }

        sleep_ms(2000);
    }
}