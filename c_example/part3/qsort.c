#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b); 
// const는 함수 내부에서 상수처럼 쓰겠다라는 의미, void는 원형 여러 타입 대응가능, *a는 주소값으로 받아오겠다라는 의미
// void* 안쪽의 데이터 모름
int main(void)
{
    int nums[10] = {11, 15, 55, 46, 2, 4, 87, 23, 45, 77};
    int indexN = sizeof(nums) / sizeof(int); // 첫번째는 항상 소문자로

    // qsort(배열, 타입-숫자, 원소의 사이즈(int = 4/sizeof연산자), 비교하는 함수의 타입)
    qsort(nums, indexN, sizeof(int), compare);

    for (int i = 0; i < indexN; ++i)
    {
        printf("%d ", nums[i]);
    }
    
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // a는 주소, int* 인트 주소로 바꿔라. 산수연산자를 사용하기 위해 int. *주소가 가리키는 값 참조
}
