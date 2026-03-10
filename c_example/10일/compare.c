#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int a, b;
    bool greater = false;
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &a, &b);

    greater = a > b; // a가 b보다 크면 true, 그렇지 않으면 false
    printf("greater 의 값은 %d 이다.", greater);
    if(greater==true)
    {
        printf("a가 더 크다.\n");
    }
    else
    {
        printf("a가 더 작다.\n");
    }
    return 0;
}