#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t FND_DATA_TBL[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X67, 0X77, 0X7C, 0X39, 0X5E, 0X79, 0X71, 0X08, 0X80};
volatile uint8_t time_s = 0x01;
volatile uint8_t timer1_cnt;

int main()
{
    DDRA = 0xFF; // fnd 출력 설정
    DDRE = 0x00; //  스위치 입력 설정

    TCCR1A = 0x00;
    TCCR1B = 0x05; // 분주비 1024 // 16M/1024/65535 -> 0.238Hz 1초/0.238 = 4.2초

    OCR1A = 14400; // 65535 = 2^16 -> 14400에서 trigger 준다. 16M/1024/14400 = 1.085Hz 0.92초
    OCR1B = 28800; // 65535 = 2^16 -> 14400에서 trigger 준다. 0.542Hz 1.8초
    TIMSK = _BV(OCIE1A) | _BV(OCIE1B) | _BV(TOIE1);
    sei();

    PORTA = FND_DATA_TBL[0];
    while (1)
    {
        PORTA = FND_DATA_TBL[time_s];
        if (time_s > 10)
            time_s = 0;
    }
    return 0;
}

ISR(TIMER1_COMPA_vect)
{
    cli();
    time_s++;
    sei();
}

ISR(TIMER1_COMPB_vect)
{
    cli();
    time_s--;
    sei();
}

ISR(TIMER1_OVF_vect)
{
    cli();
    time_s++;
    sei();
}
