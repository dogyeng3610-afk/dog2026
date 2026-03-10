#include <stdio.h>
#include <stdint.h>
#define BOLD 0x01
#define ITALIC (0x01 << 1)
#define SHADOW (0x01 << 2)
#define UNDERLINE (0x01 << 3)
// 0b00000001
// 0b00000010
// 0b00000100

int main()
{
    // unsigned char attr;
    uint8_t attr;       // 8비트 부호 없는 정수형
    attr = attr ^ attr; // 0으로 초기화
    attr = attr | BOLD;
    // 1번 옵션 T로 만들기, 앞에 있는 데이터 유지 16비트 0x01
    // attr = attr + BOLD; // 더하기도 할 수 있지만 이상이 발생할 수 있음
    printf("attr : 0x%02x\n", attr);
    attr = attr | (ITALIC + SHADOW); // 2번 3번을 T로 만들기 16비트 0x02 0x04
    printf("attr : 0x%02x\n", attr);
    attr = attr & (~BOLD); // 1번 옶션 F로 만들기, 앞에 있는 데이터 유지
    printf("attr : 0x%02x\n", attr);
    // 0b 이진을 표현
    if (attr & BOLD)
    {
        printf("BOLD 옵션은 활성화 되었습니다.");
    }
    else
    {
        printf("BOLD 옵션은 비활성화 되었습니다.");
    }

    if ((attr & ITALIC) >> 1)
    {
        printf("ITALIC 옵션은 활성화 되었습니다.");
    }
    else
    {
        printf("ITALIC 옵션은 비활성화 되었습니다.");
    }

    return 0;
}