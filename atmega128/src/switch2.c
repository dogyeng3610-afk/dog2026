#include <avr/io.h>
#include <util/delay.h>

int main()
{
    uint8_t switch_flag = 0, switch_flag_pre = 0x01;

    DDRC = 0x0F;  // 출력 선언
    DDRE = 0x00;  // 입력 선언
    PORTC = 0x00; // LED 끄기

    while (1)
    {
        switch_flag = PINE >> 4;                                                                              // 데이터 읽기 하위비트 읽기
        if ((switch_flag == 0x01) || (switch_flag == 0x02) || (switch_flag == 0x04) || (switch_flag == 0x08)) //  하나만 누를 때 체크, 동시에 눌렀을 때 인식x
        {
            switch_flag_pre = switch_flag;
        }
        PORTC ^= 0x0F;
        if (switch_flag_pre == 0x01)
            _delay_ms(250);
        else if (switch_flag_pre == 0x02)
            _delay_ms(500);
        else if (switch_flag_pre == 0x04)
            _delay_ms(750);
        else if(switch_flag_pre == 0x08)
                _delay_ms(1000);
    }
    return 0;
}