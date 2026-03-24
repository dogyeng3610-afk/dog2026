#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t led_data = 0x00;
volatile uint8_t timer0_cnt = 0;
ISR(TIMER0_OVF_vect);

int main()
{
    DDRC = 0x0F;

    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00); // 분주비
    TIMSK = _BV(TOIE0);
    sei();

    while (1)
    {
        if (timer0_cnt == 100)
        {
            led_data++;
            if (led_data > 0x0F)
                led_data = 0;
            timer0_cnt = 0;
        }
        PORTC = led_data;
    }
    return 0;
}

ISR(TIMER0_OVF_vect)
{
    cli(); // SREG I 비트 해제
    TCNT0 = 112;
    timer0_cnt++;
    sei(); // 다시 설정
}