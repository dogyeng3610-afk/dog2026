#include "serial.h"

int getSerialNumber(void)
{
    static int count = 0; // 함수는 stacte가 쌓임 -> 초기화
    int result = count;
    ++count;
    return result;
}
/* 링킹
cmake에 명시 */