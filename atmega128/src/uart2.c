#include "uart0.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>




FILE OUTPUT = FDEV_SETUP_STREAM(uart0Transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, uart0Receive, _FDEV_SETUP_READ);

int main(void)
{
    uart0Init();
    stdin = &INPUT;
    stdout = &OUTPUT;
    uint8_t numbers[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X67, 0X77, 0X7C, 0X39, 0X5E, 0X79, 0X71, 0X08, 0X80};
    uint8_t rx_data;
    DDRA = 0xFF;

    printf("hi, I'm Atmega128");
    fflush(stdout); // 출력 버퍼 비우기

    while (1)
    {
        scanf("%c", &rx_data);
        if ((rx_data >= 0x30) && (rx_data <= 0x39)) // ASCII 숫자
        {
            PORTA = numbers[rx_data - 0x30];
        }
    }
    return 0;
}