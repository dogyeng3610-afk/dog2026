#include <stdio.h>
void swap(int *a, int *b); // * : 주소에 대한 값을 얻어내는 것

int main(void)
{
    int nums[10] = {11, 15, 55, 46, 2, 4, 87, 23, 45, 77};
    int indexN = sizeof(nums) / sizeof(int); // 첫번째는 항상 소문자로

    for (int i = indexN - 1; i > 1; --i) // i : 비교 개수
    {
        for (int j = 0; j < i; ++j) // j : 버블이 올라오는 위치
        {
            if (nums[j] > nums[j + 1]) // 비교 -> 부등호 방향에 따라 오름차순, 내림차순
            {
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }
    for (int i = 0; i < indexN; ++i) // nums 배열 읽기
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