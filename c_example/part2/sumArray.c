// random으로 int 배열 10개짜리 배열을 만들어서 값을 넣고, 총합을 계산하는 프로그램
#include <stdio.h>
#include <stdlib.h> // 난수
#include <time.h>   // 시간이나 전류값

int main(void)
{
    int arr[10];
    srand(time(NULL));
    int sum = 0;

    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand() % 10 + 1;
        printf(" %d", arr[i]);
        sum = sum + arr[i];
    }
    printf("배열의 총합은 %d이다.\n", sum);
    return 0;
}