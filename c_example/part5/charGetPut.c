#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];
    printf("문자를 입력하세요:");
    ch = getc(stdin);  // 매크로
    ch = fgetc(stdin); // 함수형, getc와 기능 동일
    ch = getchar();    // fgetc와 동일 stdin을 안써도 됨
    // 결과 8->9->11? : getc -> read()는 버퍼에 문자(데이터)가 올 때까지 대기 a/n
    // 9 fgetc -> read() 버퍼에 어떤 데이터라도 들어있다면 대기x 버퍼 : /n
    // 10 getchar() a 버퍼 : /n
    printf("%d,%d,%d", stdin->_fileno, stdout->_fileno, stderr->_fileno);
    printf("입력한 문자는 %c 입니다.\n", ch);
    // 버퍼를 지움 ↑
    while (getchar() != '\n')
        ;
    ch = fgetc(stdin);
    printf("입력한 문자는 %c입니다.\n", ch);
    scanf("%s", str); // 버퍼를 지우고
    printf("입력한 문자열은 %s입니다.", str);
    return 0;
}