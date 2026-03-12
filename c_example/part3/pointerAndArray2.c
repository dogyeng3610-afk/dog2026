#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5}; // 배열 선언
    int *p;                       // 포인터 선언

    p = nums; // p가 nums의 주소를 가짐
    // p = p;
    *(p + 1) = *(p + 2); // p+2의 주소를 p+1로 넘기겠다.
    p = (p + 1);
    for (int i = 0; i < 5; ++i)
    {
        printf("nums : %d\t", nums[i]);
        printf("*(p+%d) : %d\t", i, *(p + i));
        printf("*(nums+%d):%d\t", i, *(nums + i));
        printf("p[%d] : %d\n", i, p[i]); // 포인터도 배열의 형식처럼 접근 가능
    }

    for (int i = 0; i < 5; ++i)
    {
        printf("nums : %p\t", nums);
        printf("*(p+%d) : %p\t", i, (p + i));
        printf("*(nums+%d) : %p\t", i, (nums + i));
        printf("p[%d] : %p\n", i, &p[i]);
    }
    return 0;
}