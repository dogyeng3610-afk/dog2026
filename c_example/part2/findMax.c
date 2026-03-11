// 최대값 찾기 - 순회
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXINDEX 7 // 몇 개 할지 고민시 사용

int main(void)
{
    srand(time(NULL));
    int nums[10];
    for (int i = 0; i < MAXINDEX; ++i)
    {
        nums[i] = rand() % 30;
        printf("%d ", nums[i]);
    }
    int max;
    max = nums[0];
    for (int i = 0; i < MAXINDEX; ++i)
    {
        if (max < nums[i])
        {
            max = nums[i];
        }
        else
        {
            max = max;
        }
    }
    printf("최대값 : %d\n", max);
    return 0;
}