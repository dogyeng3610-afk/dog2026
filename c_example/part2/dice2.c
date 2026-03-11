#include <stdio.h>
#include <stdlib.h> // 난수
#include <time.h>   // 시간이나 전류값

int main(void)
{
    int dice[30];
    srand(time(NULL)); // 난수의 시드값을 현재 시간으로 설정
    for (int i = 0; i < 30; ++i)
    {
        dice[i] = rand() % 6 + 1;
        printf("%d ", dice[i]); // 배열의 값
        printf("%p ", &dice[i]); // 배열의 주소 출력 %p 포인터 약자
    }
    printf("\n");
    for (int i = 0; i < 30; ++i)
    {
        dice[i] *= 10; // 값 변경 시 주소 동일한가?
        printf("%d ", dice[i]);
        printf("%p ", &dice[i]);
    }
    printf("\n");
    return 0;
/*     
주소의 크기를 보면 32bit, 4byte
2 0x7ffec34f7a50 5 0x7ffec34f7a54 1 0x7ffec34f7a58 주소 뒤 4씩 증가
 */
}