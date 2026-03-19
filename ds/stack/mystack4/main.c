#include "stack4.h"

int main(void)
{
    Stack s1, s2;

    initStack(&s1, 10, sizeof(int));
    initStack(&s2, 100, sizeof(double));

    int i = 100;
    push(&s1, &i);
    i = 200;
    push(&s1, &i);
    i = 300;
    push(&s1, &i);

    int re;
    pop(&s1, &re);
    printf("s1 첫 pop() 리턴 값 : %d\n", re);
    pop(&s1, &re);
    printf("s1 두번째 pop() 리턴 값 : %d\n", re);
    pop(&s1, &re);
    printf("s1 세번째 pop() 리턴 값 : %d\n", re);

    double d = 1.1;
    push(&s2, &d);
    d = 2.2;
    push(&s2, &d);
    d = 3.3;
    push(&s2, &d);

    double re2;
    pop(&s2, &re2);
    printf("s2 첫 pop() 리턴 값 : %lf\n", re2);
    pop(&s2, &re2);
    printf("s2 두번째 pop() 리턴 값 : %lf\n", re2);
    pop(&s2, &re2);
    printf("s2 세번째 pop() 리턴 값 : %lf\n", re2);

    printf("s1 메모리 사이즈는: %d\n", s1.size);
    printf("s2 메모리 사이즈는: %d\n", s2.size);

    // // size를 넘겼을 때 assert작동 확인
    // for (int i = 0; i < 101; ++i)
    // {
    //     push(&s2, i);
    //     printf("%d, \n", i);
    // }

    // // 데이터가 없을 때 assert작동 확인
    // for (int i = 0; i < 102; ++i)
    // {
    //     printf("%d번째 pop() : %d\n", i, pop(&s2));
    // }

    cleanupStack(&s1);
    cleanupStack(&s2);
    return 0;
}