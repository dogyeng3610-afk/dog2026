#include <stdio.h>
#include <stdbool.h>

bool arrayCompare(int *array, int *array2, int index, int *diff);


int main(void)
{
    int nums[] = {1, 2, 7, 4, 9};
    int nums2[] = {1, 2, 7, 4, 9};
    int nums3[] = {1, 2, 7, 9, 5};

    // (nums == nums2) 안됨 배열명은 첫번째 주소
    int diff = 0;

    // 함수 return값을 받아 if or else
    if (arrayCompare(nums, nums2, 5, &diff)) // main의 diff를 arrayCompare함수에서 수정할 수 있도록
    {
        printf("두 배열은 같다.");
    }
    else
    {
        printf("두 배열은 같지 않다. %d index가 다르다.", diff);
    }


    if (arrayCompare(nums3, nums2, 5, &diff))
    {
        printf("두 배열은 같다.");
    }
    else
    {
        printf("두 배열은 같지 않다. %d index가 다르다.", diff);
    }

    return 0;
}


bool arrayCompare(int *array, int *array2, int index, int *diff)
{
    int i;
    // array[i]와 array2[i]가 다르면 나가
    for (i = 0; i < index; ++i)
    {
        if (array[i] != array2[i])
        {
            break;
        }
    }
    *diff = i;

    // 완전히 같다면 i는 5, 배열이 중간에 달라서 나가면 i는 다른 숫자
    if (i == index)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 함수에서 나오는 값는 t or f
