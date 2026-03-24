#include <avr/io.h>

int main()
{
    DDRC = 0x0F; //led
    DDRE = 0x00; //switch
    uint8_t switch0;
    while(1){
        switch0 = PINE; // 레지스트리에서 정보 읽어옴 0b00010000 -> 0b 0101 0000
        PORTC = switch0 >> 4; // 0b 0000 0101
        // ... 시간이 걸리는 코드(스위치 인식 속도 느려짐) => 인터럽트로 스위치 제어
    }
    return 0;
}