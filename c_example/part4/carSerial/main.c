#include "serial.h"
#include <stdio.h>
#include "serial.h"
// int count = 0; 전역변수를 사용하거나 static

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        int num = getSerialNumber();
        printf("HYUNDAI_MOTOR_%010d\n", num); //
    }
    return 0;
}
// ->.c
// 전역변수 보안 취약