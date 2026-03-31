#include <stdio.h>
#include "pico/stdlib.h"
// #include "hardware/adc.h"   // 조도센서 사용 안함
#include "hardware/gpio.h"

#define DHT_PIN 15
// #define LIGHT_ADC 0   // 조도센서 사용 안함

//--------------------------------------
// DHT 읽기 함수
//--------------------------------------
bool read_dht(float *temperature, float *humidity)
{
    uint8_t data[5] = {0};

    gpio_set_dir(DHT_PIN, GPIO_OUT);
    gpio_put(DHT_PIN, 0);
    sleep_ms(20);
    gpio_put(DHT_PIN, 1);
    sleep_us(30);
    gpio_set_dir(DHT_PIN, GPIO_IN);

    if (gpio_get(DHT_PIN)) return false;
    while (!gpio_get(DHT_PIN));
    while (gpio_get(DHT_PIN));

    for (int i = 0; i < 40; i++)
    {
        while (!gpio_get(DHT_PIN));
        sleep_us(30);

        if (gpio_get(DHT_PIN))
            data[i / 8] |= (1 << (7 - (i % 8)));

        while (gpio_get(DHT_PIN));
    }

    if ((data[0] + data[1] + data[2] + data[3]) != data[4])
        return false;

    *humidity = data[0];
    *temperature = data[2];

    return true;
}

//--------------------------------------
// 메인
//--------------------------------------
int main()
{
    stdio_init_all();
    sleep_ms(2000); // USB 안정화

    // GPIO init
    gpio_init(DHT_PIN);

    // --- 조도센서 비활성화 ---
    /*
    adc_init();
    adc_gpio_init(26);
    adc_select_input(LIGHT_ADC);
    */

    printf("[SYSTEM] Boot complete\n");
    printf("[SYSTEM] Sensor start (DHT only)\n");

    while (1)
    {
        float temp = 0.0f, humi = 0.0f;

        // DHT 읽기
        bool dht_ok = read_dht(&temp, &humi);

        // --- 조도 읽기 비활성화 ---
        // uint16_t light_raw = adc_read();

        // 출력
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