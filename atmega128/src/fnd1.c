#include <avr/io.h>
#include <util/delay.h>

int main()
{
    uint8_t FND_DATA_TBL[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X67, 0X77, 0X7C, 0X39, 0X5E, 0X79, 0X71, 0X08, 0X80};
    uint8_t cnt = 0;
    DDRA = 0xFF;

    while (1)
    {
        PORTA = FND_DATA_TBL[cnt];
        cnt++;
        if (cnt > 13)
            cnt = 0;
        _delay_ms(500);
    }
    return 0;
}