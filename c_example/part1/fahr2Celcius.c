#include <stdio.h>

int main()
{
    int fahr;
    printf("F 온도를 입력하세요");
    scanf("%d", &fahr);
    double celsius;
    celsius = ((double)fahr - 32.0) / 1.8;
    printf("C(celsius) 온도 : %.2f\n", celsius);
    return 0;
}