#include <stdio.h>

int main(void)
{
    int nums[5] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 2, 3, 4, 5};   // 4번과 동일, 생략, 초기화한 설정 따라
    int nums3[10] = {1, 2, 3, 4, 5}; // 나머지 0
    int nums4[50];                   // 선언만/ 초기화 x, 나머지 랜덤값
    int nums5[50] = {0};             // 50개 전부다 초기화
// 9번보다 8번이 더 효율적 but 값을 넣어서 사용해야 한다.

    int n = sizeof(nums3) / sizeof(int);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", nums3[i]);
    }
    printf("\n");

    return 0;
}