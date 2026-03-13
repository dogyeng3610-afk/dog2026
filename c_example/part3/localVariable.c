#include <stdio.h>

int add(int a, int b); // 선언

int main(void)
{
    int first = 43, second = 72;
    printf("%d + %d = %d", first, second, add(first, second));
    return 0;
}

int add(int a, int b) // 정의 선언(원형)과 동일해야한다. // int a = first; int b = second; - 대입
{
    return a + b;
}
// 데이터 복사 메모리 사용 증가 주의, 무조건적 사용 자제
// 포인터 넘기기를 통해 데이터 복사 x