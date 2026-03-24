#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile int cnt = 0; // 전역변수(정수) 선언, MCU-main에서 활용되지 않는 함수는 volatile로 설정하지 않으면 생략
int main(void)
{
    // fnd init()
    uint8_t FND_DATA_TBL[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X67};
    DDRA = 0xFF;

    // 인터럽트 설정
    EICRB = _BV(ISC41) | _BV(ISC40);
    EIMSK |= _BV(INT4);
    EICRB |= _BV(ISC51) | _BV(ISC50);
    EIMSK |= _BV(INT5);
    sei();

    while (1)
    {
        PORTA = FND_DATA_TBL[cnt];
        _delay_ms(100);
    }
}

// SIGNAL(INT4_vect) SIGNAL보다 ISR 사용
ISR(INT4_vect)
{
    cli(); // SREG I 비트 해제
    cnt = (cnt + 1) % 10;
    sei(); // 다시 설정
}
ISR(INT5_vect)
{
    cli(); // SREG I 비트 해제
    cnt--;

    if (cnt < 0)
        cnt = 9;
    sei(); // 다시 설정
}