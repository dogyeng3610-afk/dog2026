#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    int *p;

    p = nums;
    p = &nums[0];
    // nums = &nums[0]
    ++p; // 포인트 연산
    printf("*p : %d\n", *p);
    return 0;
}