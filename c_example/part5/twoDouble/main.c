#include "twoDouble.h"

int main(void)
{
    Vision robot;

    printf("시력 입력:");
    scanf("%lf %lf", &robot.left, &robot.right);  // 연산자의 우선순위에 따라 ()사용
    exchange(&robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);
    return 0;
}

