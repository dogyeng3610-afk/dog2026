#include <stdio.h>
void swap(int *a, int *b); // * : 주소에 대한 값을 얻어내는 것

int main(void)
{
    int nums[10] = {11, 15, 55, 46, 2, 4, 87, 23, 45, 77};
    int indexN = sizeof(nums) / sizeof(int); // 첫번째는 항상 소문자로
    for (int i = 0; i < indexN; ++i) // 배열 앞자리
    {
        for (int j = i + 1; j < indexN; ++j) // 배열 뒤자리
        {
            if (nums[i] > nums[j]) // 비교 -> 부등호 방향에 따라 오름차순, 내림차순
            {
                swap(&nums[i], &nums[j]);
            }
        }
    }
    for (int i = 0; i < indexN; ++i) 
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a, int *b) // return 없으면 void
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}