#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "hardware/sync.h"

#define NODE_TAG "[NODE_A]"

//--------------------------------------
// 핀 설정
//--------------------------------------
#define DHT_PIN 15

// CDS (LDR) 입력 ADC 핀 (GPIO27 = ADC1)
#define CDS_GPIO 27
#define CDS_ADC_CHANNEL 1

#define CDS_SAMPLE_COUNT 10

//--------------------------------------
// DHT 읽기용 함수
//--------------------------------------
bool wait_for_level(bool level, uint32_t timeout_us)
{
    uint32_t start = time_us_32();
    while (gpio_get(DHT_PIN) != level)
    {
        if ((time_us_32() - start) > timeout_us)
            return false;
    }
    return true;
}

uint16_t read_cds_average(void)
{
    uint32_t sum = 0;
    for (int i = 0; i < CDS_SAMPLE_COUNT; i++)
    {
        sum += adc_read();
        sleep_ms(5);
    }
    return (uint16_t)(sum / CDS_SAMPLE_COUNT);
}

bool read_dht(float *temperature, float *humidity)
{
    uint8_t data[5] = {0};

    // 시작 신호는 인터럽트 켠 상태에서 처리
    gpio_set_dir(DHT_PIN, GPIO_OUT);
    gpio_put(DHT_PIN, 0);
    sleep_ms(20);
    gpio_put(DHT_PIN, 1);
    sleep_us(30);
    gpio_set_dir(DHT_PIN, GPIO_IN);

    uint32_t irq_state = save_and_disable_interrupts();

    if (!wait_for_level(0, 150))
        goto fail;
    if (!wait_for_level(1, 150))
        goto fail;
    if (!wait_for_level(0, 150))
        goto fail;

    for (int i = 0; i < 40; i++)
    {
        if (!wait_for_level(1, 100))
            goto fail;

        sleep_us(30);

        if (gpio_get(DHT_PIN))
            data[i / 8] |= (1 << (7 - (i % 8)));

        if (!wait_for_level(0, 100))
            goto fail;
    }

    restore_interrupts(irq_state);

    if ((uint8_t)(data[0] + data[1] + data[2] + data[3]) != data[4])
    {
        printf("%s DHT checksum fail (%u,%u,%u,%u,%u)\n",
               NODE_TAG, data[0], data[1], data[2], data[3], data[4]);
        return false;
    }

    // DHT11 기준
    *humidity = (float)data[0];
    *temperature = (float)data[2];

    return true;

fail:
    restore_interrupts(irq_state);
    printf("%s DHT signal timeout fail\n", NODE_TAG);
    return false;
}

//--------------------------------------
// 메인
//--------------------------------------
int main()
{
    stdio_init_all();
    sleep_ms(2000);

    // DHT 초기화
    gpio_init(DHT_PIN);
    gpio_set_dir(DHT_PIN, GPIO_OUT);
    gpio_put(DHT_PIN, 1);
    gpio_pull_up(DHT_PIN);

    // ADC 초기화 (CDS)
    adc_init();
    adc_gpio_init(CDS_GPIO);
    adc_select_input(CDS_ADC_CHANNEL);

    printf("%s BOOT OK\n", NODE_TAG);
    printf("%s CDS ADC OK (GPIO%d / ADC%d)\n", NODE_TAG, CDS_GPIO, CDS_ADC_CHANNEL);
    printf("%s DHT11 GPIO=%d\n", NODE_TAG, DHT_PIN);

    float last_temp = 0.0f;
    float last_humi = 0.0f;
    bool has_valid_dht = false;

    while (true)
    {
        uint16_t light = read_cds_average();

        float temp = 0.0f;
        float humi = 0.0f;
        bool dht_ok = read_dht(&temp, &humi);

        if (dht_ok)
        {
            last_temp = temp;
            last_humi = humi;
            has_valid_dht = true;

            printf("%s light=%u temp=%.1f humidity=%.1f\n",
                   NODE_TAG, light, temp, humi);
        }
        else
        {
            if (has_valid_dht)
            {
                printf("%s light=%u temp=%.1f humidity=%.1f (cached)\n",
                       NODE_TAG, light, last_temp, last_humi);
            }
            else
            {
                printf("%s light=%u temp=ERR humidity=ERR\n",
                       NODE_TAG, light);
            }
        }

        sleep_ms(1500);
    }

    return 0;
}