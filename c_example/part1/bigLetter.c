#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    printf("char를 입력하세요: ");
    scanf("%c", &ch); // &주소 연산자

    bool isBig;
    isBig = ('A' <= ch) && (ch <= 'Z'); // 대문자 범위 체크/ 비교 연산자, 논리 연산자 => char'A'는 숫자
    printf("%c는 %s", ch, isBig? "대문자 입니다." : "대문자가 아닙니다.");
    return 0;
}