#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];
    printf("문자를 입력하세요:");
    ch = getc(stdin); // 매크로
    ch = fgetc(stdin); // 함수형, getc와 기능 동일
    ch = getchar(); // fgetc와 동일 stdin을 안써도 됨
    printf("%d,%d,%d", stdin->_fileno, stdout->_fileno, stderr->_fileno);
    printf("입력한 문자는 %c 입니다.\n", ch);

    return 0;
}