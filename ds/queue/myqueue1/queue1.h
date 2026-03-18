#pragma once
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

typedef struct
{
    int array[STACKSIZE];
    int *front;
    int *rear;
}Stack;

void initStack(Stack *ps);
void push(Stack *ps, int data);
int pop(Stack *ps);