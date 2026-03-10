#include <stdio.h>
// 전위는 먼저 증가한 후에 값을 사용하고, 후위는 먼저 값을 사용한 후에 증가합니다.
int main(void)
{
    int a, b;
    a = 5;
    b = ++a; // a가 먼저 증가한 후 b에 할당
    printf("a : %d \t b : %d\n", a, b);

    a = 5;
    b = a++; // b에 a의 현재 값이 할당된 후 a가 증가
    printf("a : %d \t b : %d\n", a, b);

    printf("a : %d \t b: %d\n", a, a++); // a의 현재 값이 먼저 출력된 후 a가 증가
    printf("a : %d \t b: %d\n", a, ++a); // a가 먼저 증가한 후 a의 새로운 값이 출력

    return 0;
}