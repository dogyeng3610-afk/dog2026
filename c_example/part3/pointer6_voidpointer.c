#include <stdio.h>

int main(void)
{
    int i = 100;
    double d = 3.14;

    void *p;

    p = &i;
    // *p = 200;//void 포인터는 역참조x
    // 타입캐스팅을 해서 역참조
    *(int *)p = 200;
    // 타입캐스팅을 해도 void 포인트가 아닌게 아니다. 다시 사용하려면 다시 타입캐스팅

    p = &d;
    *(double *)p = 2.718;
    printf("i : %d, d : %f, *p : %f\n", i, d, *(double *)p);

    printf("i : %d, *p : %d", i, *(int *)p);
    return 0;
} // 여러 가지 자료형을 담을 수 잇다.