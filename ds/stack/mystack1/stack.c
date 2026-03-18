#include "stack.h"

static int stack[100];
static int tos = 0;

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