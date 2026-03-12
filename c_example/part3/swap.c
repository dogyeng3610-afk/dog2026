#include <stdio.h>

void swap(int *a, int *b); // *a 주소
void info(int a, int b);

int main(void)
{
    int a, b, temp;
    a = 100;
    b = 200;

    info(a, b);
    // temp = a;
    // a = b;
    // b = temp;
    swap(&a, &b);
    info(a, b);

    return 0;
}

void swap(int *a, int *b) // return 없으면 void
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void info(int a, int b)
{
    printf("a: %d, b: %d\n", a, b);
}