#include "queue2.h"

int main(void)
{
    Qu qu1, qu2;

    initQueue(&qu1);
    initQueue(&qu2);

    push(&qu1, 100);
    push(&qu1, 200);
    printf("첫번째 pop():%d\n", pop(&qu1));

    push(&qu1, 300);
    printf("두번째 pop():%d\n", pop(&qu1));
    printf("세번째 pop():%d\n", pop(&qu1));
    push(&qu2, 700);
    push(&qu2, 800);
    printf("첫번째 pop():%d\n", pop(&qu2));

    push(&qu2, 900);
    printf("두번째 pop():%d\n", pop(&qu2));
    printf("세번째 pop():%d\n", pop(&qu2));

    // max index를 넘어갔을 때 101개를 채울때
    for (int i = 0; i < 99; ++i)
    {
        push(&qu2, i);
        printf("%d, \n", i);
    }

    // 데이터가 부족할 때
    for (int i = 0; i < 30; ++i)
    {
        printf("%d번째 pop() : %d\n", i, pop(&qu2));
    }

    return 0;
}