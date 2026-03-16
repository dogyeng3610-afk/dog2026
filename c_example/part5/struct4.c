#include <stdio.h>
typedef struct vision
{
    double left;
    double right;
}Vision;

void exchange(Vision *robot);

int main(void)
{
    Vision robot;

    printf("시력 입력:");
    scanf("%lf %lf", &robot.left, &robot.right);  // 연산자의 우선순위에 따라 ()사용
    exchange(&robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);
    return 0;
}

void exchange(Vision *robot)
{
    double temp;
    temp = robot->left;
    (*robot).left = (*robot).right;
    robot->right = temp;
}