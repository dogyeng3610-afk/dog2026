#include <stdio.h>

int main(void)
{
    // 자동으로 바뀌지 않으면 명시적으로 타입캐스팅을 사용하면 된다.
    int man, woman;
    double sum, manRate, womanRate;
    // 선언부에 의해 결정된 타입은 변하지 않음
    printf("남자의 수는 :");
    scanf("%d", &man);
    printf("여자의 수는 :");
    scanf("%d", &woman);
    // 더블 캐스팅이 어딘가에 되어있다. 편의성
    sum = man + woman;             // man(int) + woman(int) = sum은 int아니라 double이므로 값은 double
    womanRate = woman / sum * 100; // woman은 int지만 sum은 double 값은 double로
    manRate = man / sum * 100;

    printf("남자의 수는 %d명이고 여자의 수는 %d명이다. \n", man, woman);
    printf("총 수는 %.f명 \n 남자의 비율은 %.2f\n여자의 비율은 %.2f\n", sum, manRate, womanRate);
    return 0;
}