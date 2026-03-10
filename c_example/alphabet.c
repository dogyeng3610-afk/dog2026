// 입력받은 char가 알파벳인지 아닌지 확인
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    printf("문자를 입력하세요: ");
    scanf("%c", &ch);

    bool isBig;
    isBig = ('A' <= ch) && (ch <= 'Z') || ('a' <= ch) && (ch <= 'z');
    printf("%c는 %s", ch, isBig ? "알파벳 입니다." : "알파벳이 아닙니다.");
    return 0;
}