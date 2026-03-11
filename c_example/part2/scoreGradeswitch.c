#include <stdio.h>

int main(void)
{
    int score;
    char grade = 'F';
    printf("점수를 입력하세요:\t");
    scanf("%d", &score);

    switch (score / 10)
    {
    case 10:
        grade = 'A';
        break;
    case 9:
        grade = 'A';
        break;
    case 8:
        grade = 'B';
        break;
    case 7:
        grade = 'C';
        break;
    case 6:
        grade = 'D';
        break;
    default:
        grade = 'F';
        break;
    }
    printf("%d는 %c 등급입니다.\n", score, grade);
    return 0;
}