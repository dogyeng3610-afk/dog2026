// PINE0 -> +1, PINE1 -> -1 0~9

#include <avr/io.h>
#include <util/delay.h>

int main()
{
    uint8_t FND_DATA_TBL[] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X67};
    int cnt = 0;
    uint8_t switch_flag, switch_flag_pre;
    DDRA = 0xFF;
    DDRE = 0x00;

    while (1)
    {
        if (switch_flag != (PINE >> 4))
        {
            switch_flag = PINE >> 4;
            if ((switch_flag == 0x01) || (switch_flag == 0x02))
            {
                switch_flag_pre = switch_flag;
            }

            if (switch_flag_pre == 0x01)
            {
                cnt++;
            }
            else if (switch_flag_pre == 0x02)
            {
                cnt--;
            }
            switch_flag_pre = 0;

            cnt = cnt % 10;

            if (cnt < 0)
            {
                cnt = 9;
            }

            PORTA = FND_DATA_TBL[cnt];
        }
    }
    return 0;
}