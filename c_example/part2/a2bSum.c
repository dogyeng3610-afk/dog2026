// 입력받은 a,b를 사용해 a에서 b까지의 합 구하기
#include <stdio.h>

int main(void)
{
    int a, b;
    printf("a와 b를 입력하세요:\t");
    scanf("%d %d", &a, &b);

    int sum = 0;

    for (int i = a; i <= b; ++i)
    {
        sum = sum + i;
    }
    printf("a부터 b까지의 합은: %d\n", sum);
    return 0;
}