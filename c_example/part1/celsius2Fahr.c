#include <stdio.h>

int main()
{
    int celsius;
    printf("C 온도를 입력하세요");
    scanf("%d", &celsius);
    double fahr;
    fahr = 1.8 * (double)celsius + 32.0;
    printf("F(fahr) 온도 : %.2f\n", fahr);
    return 0;
}