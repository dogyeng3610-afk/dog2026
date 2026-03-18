#include <stdio.h>

void push(int data);
int pop(void);
int stack[50];
int tos = 0; // top of stack
// 전역변수일 경우 초기화x 지역변수는 초기화 필요
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

void push(int data)
{
    stack[tos] = data;
    ++tos;
    // tos = tos + 1;
}
int pop(void)
{
    --tos;
    return stack[tos];
}