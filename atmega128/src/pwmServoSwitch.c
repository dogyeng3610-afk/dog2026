// 버튼을 누르면 0도, 45도 90도, 135도 로 이동
// lcd에 각도 표시

#include "lcd.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

int main(void)
{
    uint8_t switch_flag = 0, switch_flag_pre = 0x01;

    DDRE = 0x00; // switch
    DDRE |= _BV(PE3);

    TCCR3A = _BV(COM3A1) | _BV(WGM31);
    TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS31);
    // 분주비 8, fast pwm , timer3 oc 3a

    ICR3 = 40000; // 20ms 50hz .. 2000000-> 1초 ?? -> 0.02초
    OCR3A = 3000; // 40000 : 20 ?(2000 ~ 4000) : 1~2 = ?? : 1.5 (2000 ~ 4000 : 0~90도)

    lcdInit();

    char buffer[16];

    while (1)
    {
        switch_flag = PINE >> 4;                                                                              // 데이터 읽기 하위비트 읽기
        if ((switch_flag == 0x01) || (switch_flag == 0x02) || (switch_flag == 0x04) || (switch_flag == 0x08)) //  하나만 누를 때 체크, 동시에 눌렀을 때 인식x
        {
            switch_flag_pre = switch_flag;
        }
        if (switch_flag_pre == 0x01)
        {
            OCR3A = 0;
            itoa(OCR3A, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        else if (switch_flag_pre == 0x02)
        {
            OCR3A = 2500;
            itoa(OCR3A, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        else if (switch_flag_pre == 0x04)
        {
            OCR3A = 3000;
            itoa(OCR3A, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        else if (switch_flag_pre == 0x08)
        {
            OCR3A = 3500;
            itoa(OCR3A, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
    }
    lcdClear();
    return 0;
}
