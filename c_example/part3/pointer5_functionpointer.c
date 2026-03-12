#include <stdio.h>

// 함수 선언
/* add 함수명 = 포인터 */

// 함수포인트를 선언할 때 agument type 일치 시키기
int add(int a, int b);
int substract(int a, int b);

int main(void)
{
    int (*fp)(int, int);
    fp = add; // add에 주소값이 들어가 있다. -> 어딘가 정의되어있는 add를 가리키고 있다. // 명확한 사용방법
    int re = (*fp)(4, 3); // 예외적인 방법
    re = fp(4, 3); // 함수가 포인터이므로 바로 대입해 사용 가능
    printf("결과 : %d\n", re);

    fp = &substract; // 주소에 주소값을 연결 // 함수만 예외적으로 앞에 주소연산자와 같이 사용
    re = (*fp)(4, 3);
    printf("결과 : %d\n", re);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int substract(int a, int b)
{
    return a - b;
}