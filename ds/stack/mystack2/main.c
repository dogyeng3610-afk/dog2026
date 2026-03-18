#include "stack2.h"
// Test Driven Develop : TDD
// DDD
// 요구 명세서! - 기능적 요소, 비기능적 요소 -> 요구 명세 개발자가 상세하게 작성 -> AI 시킴(agent 사용) -> 버그 수정 -> AI 소통(아키텍처, 문법)

int main(void)
{
    Stack s1, s2;

    initStack(&s1);
    initStack(&s2);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);

    printf("s1 첫 pop() 리턴 값 : %d\n", pop(&s1));
    printf("s1 두번째 pop() 리턴 값 : %d\n", pop(&s1));
    printf("s1 세번째 pop() 리턴 값 : %d\n", pop(&s1));

    push(&s2, 700);
    push(&s2, 800);
    push(&s2, 900);

    printf("s2 첫 pop() 리턴 값 : %d\n", pop(&s2));
    printf("s2 두번째 pop() 리턴 값 : %d\n", pop(&s2));
    printf("s2 세번째 pop() 리턴 값 : %d\n", pop(&s2));
    return 0;
}
