#include <stdio.h>


// 생략은 defalt, 임의로 배정 가능

// 비트연산과 enum을 같이 사용할 때 임의로 배정함
// SPRING + SUMMER = 3 bit = 0011
/*enum season
 {
    SPRING, // 0
    SUMMER, // 1
    FALL,   // 2
    WINTER  // 3
};
 */

 #define SPRING 0
 #define SUMMER 1
 #define FALL   2
 #define WINTER 3

 // #define SFALL 4 --> S2 = 4

int main(void)
{
    // enum season ss;
    int ss;
    char *pString = NULL;

    ss = SPRING;
    switch (ss)
    {
    case SPRING: // 0
        pString = "inline";
        break;
    case SUMMER: // 1
        pString = "swimming";
        break;
    case FALL: // 2
        pString = "trip";
        break;
    case WINTER: // 3
        pString = "skiing";
        break;
    }
    printf("나의 레저 활동 => %s\n", pString);
    return 0;
}