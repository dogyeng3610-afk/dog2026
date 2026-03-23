// git submodule add https://github.com/arduino/ArduinoCore-avr.git deps/arduino-core

#include <avr/io.h>
#include <util/delay.h>

int main()
{
    *(volatile uint8_t *)(0x14) = 0x03;
    DDRC = 0x03; // ddrc(0x14)0011 0(입력),1(출력) 울 출력 모드로 한다.
    while (1)
    {
        // PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);
        // PORTC |= _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);
        PORTC = 0x0F; // 1111 0, 1, 2, 3 번을 1(ON)->5V 출력시킴.
        _delay_ms(500); //0.5초 기다리겠다.

        PORTC = 0x00; // 0000 0, 1, 2, 3 번을 0(OFF)-> 0V 출력시킴.
        _delay_ms(500);
    }
    return 0;
}