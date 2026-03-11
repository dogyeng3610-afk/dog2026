#include <stdio.h>
#include <stdlib.h> // 난수
#include <time.h>   // 시간이나 전류값

int main(void)
{
    int dice;
    srand(time(NULL));     // 난수의 시드값을 현재 시간으로 설정
    dice = rand() % 6 + 1; // 1부터 6까지의 난수 생성
    printf("주사위의 숫자는 %d입니다.\n", dice);
    return 0;
}