#include <stdio.h>

int main()
{
    char ch1 = 'A'; // t선언과 동시에 대입
    char ch2 = 64;
    char ch3; // 선언만
    printf("ch1: %c, Numner: %d\n", ch1, ch1);
    printf("ch2: %c, Numner: %d\n", ch2, ch2);
    scanf("%c", &ch3); // 키보드로 문자 입력
    printf("ch3: %c, Numner: %d\n", ch3, ch3);
    return 0;
}