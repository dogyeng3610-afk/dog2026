#include "queue1.h"

void initStack(Stack *ps)
{
    ps->front = ps->array;
}
void push(Stack *ps, int data)
{
    *(ps->rear++) = data;
}
int pop(Stack *ps)
{
    return *(ps->front++);
}