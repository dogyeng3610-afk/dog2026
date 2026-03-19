#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct
{
    void *pArr;
    int eleSize;
    void *front;//pArr의 주소를 가리키고 있으므로
    void *rear;
    int size;
} Qu;

void initQueue(Qu *pQu, int size,int eleSize);
void cleanupStack(Qu *pQu);
void push(Qu *pQu, const void *pData);
void pop(Qu *pQu, void *pData);
int size(Qu *pQu);