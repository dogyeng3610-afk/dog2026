// int로 점수를 입력을 받아서 90점 이상 A, 80점 이상 B, 70점 이상 C, 60점 이상 D, 나머지는 F
#include <stdio.h>
#include <stdlib.h> //atoi 함수 array to integer

int main(int argc, char *argv[])
{
    int score = atoi(argv[1]);

    // int score;
    // printf("점수를 입력하세요:\t");
    // scanf("%d", &score);
    char grade = 'F';

    if (score >= 90)
    {
        grade = 'A';
    }
    else if (score >= 80)
    {
        grade = 'B';
    }
    else if (score >= 70)
    {
        grade = 'C';
    }
    else if (score >= 60)
    {
        grade = 'D';
    }
    printf("%d는 %c 등급입니다.\n", score, grade);
    return 0;
}