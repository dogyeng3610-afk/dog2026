#include "queue3.h"

int main(void)
{
    Qu qu1, qu2;

    initQueue(&qu1, 10, sizeof(int));
    initQueue(&qu2, 100, sizeof(double));

    int i = 100;
    push(&qu1, &i);
    i = 200;
    push(&qu1, &i);
    i = 300;
    push(&qu1, &i);

    int re;
    pop(&qu1, &re);
    printf("qu1 첫 pop() 리턴 값 : %d\n", re);
    pop(&qu1, &re);
    printf("qu1 두번째 pop() 리턴 값 : %d\n", re);
    pop(&qu1, &re);
    printf("qu1 세번째 pop() 리턴 값 : %d\n", re);

    double d = 1.1;
    push(&qu2, &d);
    d = 2.2;
    push(&qu2, &d);
    d = 3.3;
    push(&qu2, &d);

    double re2;
    pop(&qu2, &re2);
    printf("qu2 첫 pop() 리턴 값 : %lf\n", re2);
    pop(&qu2, &re2);
    printf("qu2 두번째 pop() 리턴 값 : %lf\n", re2);
    pop(&qu2, &re2);
    printf("qu2 세번째 pop() 리턴 값 : %lf\n", re2);

    printf("qu1 큐 메모리 사이즈는: %d\n", qu1.size);
    printf("qu2 큐 메모리 사이즈는: %d\n", qu2.size);

    // size를 넘겼을 때 assert작동 확인
    for (int i = 0; i < 101; ++i)
    {
        double d = i + 3.14;
        push(&qu2, &d);
        printf("%lf, \n", (double)i + 3.14);
    }

    // 데이터가 없을 때 assert작동 확인
    for (int i = 0; i < 102; ++i)
    {
        pop(&qu2, &re2);
        printf("%d번째 pop(): %lf\n", i, re2);
    }

    cleanupStack(&qu1);
    cleanupStack(&qu2);
    return 0;
}