// #include <avr/interrupt.h>
// #include "lcd.h"
// #include <avr/io.h>
// #include <stdlib.h>
// #include <util/delay.h>

// int main(void)
// {
//     // 서보 PWM 선 PE5
//     DDRE = _BV(PE3);

//     TCCR3A = _BV(COM3A1) | _BV(WGM31);
//     TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(WGM31);
//     // 분주비 8, fast pwm, timer 3 oc 3a

//     ICR3 = 40000; // 20ms 50hz .. 2000000 -> 1초 ?? -> 0.02초
//     // 한 pulse의 길이를 정확히 알아야 전송함. 작동가능
//     OCR3A = 3000; // compare 4000 : 20 = ? : 1~2 => 2000~4000

//     char buffer[16];
//     while (1)
//     {
//         for (int pulse = 2000; pulse <= 4000; pulse += 40)
//         {
//             OCR3A = pulse;
//             itoa(pulse, buffer, 10);
//             lcdGotoXY(0, 0);
//             lcdPrint(buffer);
//             _delay_ms(20);
//         }

//         for (int pulse = 4000; pulse <= 2000; pulse -= 40)
//         {
//             OCR3A = pulse;
//             itoa(pulse, buffer, 10); // int를 array로, 숫자를 char로
//             lcdGotoXY(0, 0);
//             lcdPrint(buffer);
//             _delay_ms(20);
//         }
//     }
//     return 0;
// }

// 
#include <lcd.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

int main(void)
{
    // 서보 PWM 선 PE5
    DDRE = _BV(PE3);

    TCCR3A = _BV(COM3A1) | _BV(WGM31);
    TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS31);
    // 분주비 8, fast pwm , timer3 oc 3a

    ICR3 = 40000; // 20ms 50hz .. 2000000-> 1초 ?? -> 0.02초
    OCR3A = 3000; // 40000 : 20 = ? : 1~2 2000 ~ 4000

    lcdInit();
    lcdClear();
    char buffer[16];

    while (1)
    {
        for (int pulse = 2000; pulse <= 4000;pulse +=40){
            OCR3A = pulse;
            itoa(pulse, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        for (int pulse = 4000; pulse >= 2000; pulse -= 40)
        {
            OCR3A = pulse;
            itoa(pulse, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
    }
    return 0;
}