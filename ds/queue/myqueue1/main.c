#include "queue1.h"

int main(void)
{
    Stack *s1;
    int size = 100;
    int count = 0;

    s1 = (Stack *)malloc(sizeof(s1) * STACKSIZE);

    initStack(&s1);

    push(&s1, 100);
    push(&s1, 200);
    printf("첫번째 pop():%d\n", pop(&s1));

    push(&s1, 300);
    printf("두번째 pop():%d\n", pop(&s1));
    printf("세번째 pop():%d\n", pop(&s1));
    free(s1);
    return 0;
}