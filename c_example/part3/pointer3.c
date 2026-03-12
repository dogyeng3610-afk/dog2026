// little endian, big endian

#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    char *p;
    p = (char *)&a; // 타입캐스팅, 타입 포인터
    printf("*p : 0x%x\n", *(p+1)); // 뒤부터 출력, 더하면 타입 수만큼 넘어가서 출력
    // 0x78이 나오면 big endian이다.

    return 0;
}