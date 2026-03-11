#include <stdio.h>
#include <stdlib.h> //atoi 함수 array to integer

int main(int argc, char *argv[]) // argc : argument count 숫자, argv : argument vector 문자열 배열
{

    // int score;
    // printf(" 점수를 입력하세요 : ");
    // scanf("%d", &score);

    int score = atoi(argv[1]); // 문자열을 정수로 변환

    if (score >= 60)
    {
        printf("점수: %d --- 합격\n", score);
    }
    else
    {
        printf("점수: %d --- 탈락\n", score);
    }

    return 0;
}
