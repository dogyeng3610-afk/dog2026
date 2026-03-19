#include "queue3.h"

void initQueue(Qu *pQu, int size, int eleSize)
{
    pQu->pArr = malloc(eleSize * size);
    assert(pQu->pArr != NULL);
    pQu->eleSize = eleSize;
    pQu->size = size;
    pQu->rear = pQu->pArr;
    pQu->front = pQu->pArr;
}
void cleanupStack(Qu *pQu)
{
    free(pQu->pArr);
}
void push(Qu *pQu, const void *pData)
{
    assert(pQu->rear != (pQu->pArr + pQu->size)); // 끝이 넘어가면 err
    pQu->rear = (unsigned char *)pQu->rear + pQu->eleSize;
    memcpy((unsigned char *)pQu->rear, pData, pQu->eleSize);
}
void pop(Qu *pQu, void *pData)
{
    assert(pQu->front != pQu->rear);
    pQu->front = (unsigned char *)pQu->front + pQu->eleSize;
    memcpy(pData, (unsigned char *)pQu->front, pQu->eleSize); // front에서 값을 빼고 앞으로 옮긴다.
}
int size(Qu *pQu)
{
    return pQu->size;
}