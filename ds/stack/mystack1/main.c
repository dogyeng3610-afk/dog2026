#include "stack.h"
// 전역 변수 사용 시
// 단점 : 배열의 사용 범위가 정해져 있다. , 보안, 다수의 스택 운영 불가능
// 포인터로 매개변수 넘기기

int main(void)
{
    push(100);
    push(200);
    push(300);

    printf("첫 pop() 리턴 값 : %d\n", pop());
    printf("두번째 pop() 리턴 값 : %d\n", pop());
    printf("세번째 pop() 리턴 값 : %d\n", pop());
    return 0;
}
