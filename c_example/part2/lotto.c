#include <stdio.h>
#include <stdlib.h> // 난수
#include <time.h>

int main(void)
{
    int lotto[6];
    int i, j;

    srand(time(NULL)); // random seed 설정 => 같은 시간일 경우 동일한 값

    for (i = 0; i < 6; ++i)
    {
        lotto[i] = (rand() % 45) + 1; // 0~44 + 1 => 1~45
        // 중복 검사
        for (j = 0; j < i; j++)
        {
            if (lotto[i] == lotto[j])
            {
                i--;
                break; // if문에서 for문으로 탈출하여 중복된 숫자 다시 생성하도록 함
            }
        }
    }
    for (i = 0; i < 6; ++i)
    {
        printf("%d ", lotto[i]);
    }
    printf("\n");
    return 0;
}