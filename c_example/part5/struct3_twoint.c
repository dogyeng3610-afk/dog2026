#include <stdio.h>
struct vision
{
    double left;
    double right;
};

struct vision exchange(struct vision robot);

int main(void)
{
    struct vision robot; // 변수 메모리 공간

    printf("시력 입력:");
    scanf("%lf %lf", &(robot.left), &(robot.right));
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);
    return 0;
}

struct vision exchange(struct vision robot) // 메모리 공간
{
    double temp;
    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;

    return robot;
}
// 메모리 낭비 