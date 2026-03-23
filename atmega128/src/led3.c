#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // unsigned char led_data = 0x00; // 1바이트 = 8bit, 4 bit 2^4 = 16 00~ff
    // unsigned char led_data = 0b00000000; // 0 1
    uint8_t led_data = 0x00;
    DDRC = 0x0F; // 하위 4개 bit 1
    // DDRC = 0b00001111;
    while (1)
    {
        PORTC = led_data;
        led_data++;
        if (led_data > 0x0F)

            led_data = 0;

        _delay_ms(500);
    }
    return 0;
}
