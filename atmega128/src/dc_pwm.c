#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);

    TCCR1A = _BV(COM1A1) | _BV(WGM11);            // compare output 끝까지 가지 않고 중간 비교
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13); // fast pwm, 분주비 8, count는 2MHz
    ICR1 = 800;                                   // 2MHz : 1초 = 800Hz : xch
    OCR1A = 560;                                  // 800 카운트 하는데 560까지만 => 70%   => 속도
    PORTD &= ~_BV(PD5);
    PORTD |= _BV(PD4);
    while (1)
    {

        _delay_ms(500);

        PORTD &= ~_BV(PD4);
        PORTD |= _BV(PD5);
        _delay_ms(500);
    }
    return 0;
}