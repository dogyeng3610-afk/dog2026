// 피라미드 형태 출력
//     *
//    ***
//   *****
//  *******
// *********

#include <stdio.h>
#include <stdlib.h> // system 함수 사용 위해 추가
#include <unistd.h> // 코드 내 리눅스 명령어 사용

int main(void)
{
    system("clear");  // 화면 지우기
    system("ls -al"); // 현재 디렉토리의 파일 목록을 자세히 출력하는 리눅스 명령어
    int height;
    printf("피라미드의 높이를 입력하세요: ");
    scanf("%d", &height);

    for (int i = 1; i <= height; ++i)
    { // space
        for (int j = 1; j <= height - i; ++j)
        {
            printf(" ");
        }
        //*
        for (int j = 1; j <= 2 * i - 1; ++j)
        {
            printf("*");
        }
        sleep(1); // 1초 대기 출력 delay
        printf("\n");
    }
    return 0;
}