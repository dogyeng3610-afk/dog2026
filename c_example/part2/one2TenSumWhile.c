#include <stdio.h>

int main(void)
{
    int sum = 0;
    int i = 1;
    while (i <= 10)
    {
        sum += i; // sum = sum + i 복합대입 연산자 += -= *= /= %=...
        i++;
    }
    printf("1부터 10까지의 합은: %d\n", sum);
    return 0;
}