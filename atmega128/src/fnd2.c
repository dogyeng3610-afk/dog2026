#include <avr/io.h>
#include <avr/interrupt.h>
// delay 함수 사용x => 모든 장치 멈춤, 되도록 사용하지 않기
// _ : 내부함수는 사용x

volatile uint8_t milliseconds = 0;

ISR(TIMER0_OVF_vect) // 오버플로어때 실행
{
    // 차단 불가능...
    ++milliseconds;
    // 차단 가능.. 이렇게 불가능과 구성해도 됨
}

void timer0_init(void) // 인터럽트
{
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);
    TIMSK = _BV(TOIE0);
    sei(); // 차단 가능성을 풀어준다. 밑에 코드 인터럽트 가능하다.
}

int main()
{
    timer0_init();
    uint8_t numbers[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X67};
    int count = 0;
    DDRA = 0xFF;
    while (1)
    {
        if (milliseconds >= 32)
        {
            count++;
            milliseconds = 0;
            count = count % 10;
            PORTA = numbers[count];
        }
    }
    return 0;
}