#include <stdio.h>

int main(void)
{
    int i = 0;
    for (; i < 10; ++i) // i를 for문 안에서 선언하면 for문이 끝나면 i는 사라진다.
    {
        printf("%d \n", i + 1);
    }
    printf("%d", i);
    return 0;
}