#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t led_data = 0x00;
volatile uint8_t timer0_cnt = 0;
ISR(TIMER0_OVF_vect);

int main()
{
    DDRC = 0x0F;

    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00); // 분주비 1024
    TIMSK = _BV(TOIE0); //개별허용
    sei(); /// 전역 허용

    while (1)
    {
        if (timer0_cnt == 100)  // 1초마다 if문 작동
        {
            led_data++; // 얼마 만큼의 시간이 흐르면 실행되는가? 얼마에 한번씩 실행되는가? -> 1초 마다 작동
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
    TCNT0 = 112; // 112~255 사이만 카운트 : 144번 카운트 // 1번 카운트 할 때 16M/1024 시간 = 15635 // 1초 -> 15635/133=117
    timer0_cnt++;
    sei(); // 다시 설정
}