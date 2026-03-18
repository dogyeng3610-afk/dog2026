#include "queue2.h"

void initQueue(Qu *pQu)
{
    pQu->front = pQu->queue; // 배열명 = 첫번재 주소값
    pQu->rear = pQu->queue;
}

void push(Qu *pQu, int data)
{
    if (pQu->rear == pQu->queue + ARRAYSIZE /* 포인터연산 */) // if문 rear가 끝까지 도달하면 처음으로 가겠다.
    {
        pQu->rear = pQu->queue;
    }
    if (pQu->rear + 1 == pQu->front) // if문
    {
        fprintf(stderr, "stack is full\n");

        exit(1); // 버퍼를 지우지 못함
    }
    *(pQu->rear++) = data;
}

int pop(Qu *pQu)
{
    if (pQu->front == pQu->front + ARRAYSIZE)
    {
        pQu->front = pQu->queue; // 초기화
    }
    if (pQu->front == pQu->rear)
    {
        fprintf(stderr, "ther is no data\n");
    }
    return *(pQu->front++);
}