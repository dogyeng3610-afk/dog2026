#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char ch = 'a';

    printf("프로그램 시작\n");
    putchar(ch);
    // fflush(stdout);
    sleep(1);
    printf("putchar 실행후\n");
    putc(ch, stdout); // 파일 스트림 지정
    fflush(stdout);
    sleep(1);
    char *string1 = "스트링1 배열입니다.";
    puts(string1); // puts은 작동 방식이 마지막에 개행 자동 추가
    sleep(1);
    fputs(string1, stdout); // 개행 추가 없음
    fflush(stdout);
    sleep(1);
    return 0;
}