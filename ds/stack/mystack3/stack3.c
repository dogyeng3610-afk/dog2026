#include "stack3.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = (int *)malloc(sizeof(int) * size); // malloc - void 포인터 리턴
    // if(ps->pArr == NULL)
    // {
    //     printf("에러");
    //     exit(1);
    // }
    assert(ps->pArr); // assert 헤더 필요
    ps->size = size;
    ps->tos = ps->pArr;
}
void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}
void push(Stack *ps, int data)
{
    assert(ps->tos != (ps->pArr + ps->size));
    *(ps->tos++) = data;
}
int pop(Stack *ps)
{
    assert(ps->tos != ps->pArr);
    return *(--ps->tos);
}
int size(Stack *ps)
{
    return ps->size;
}