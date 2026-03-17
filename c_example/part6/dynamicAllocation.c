#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *pLiteral = "리터럴 상수이다.";
    int *pInt; // 주소값
    double *pDouble;
    char LocalVariable = 'c';
    char pArray[30] = "지역 변수 (배열)";

    pInt = (int *)/*타입 캐스팅 필요*/ malloc(sizeof(int)) /*int size = 4 */ ; // 참조, heap 메모리 공간 할당 nameX -> 주소값 리턴
    if (pInt == NULL)
    {
        printf("메모리가 부족합니다.\n");
        exit(1);
    }
    pDouble = (double *)malloc(sizeof(double)); // 배열 사용할 때 사이즈 커도 됨

    *pInt = 10;
    *pDouble = 3.4;

    printf("정수형으로 사용 : %d\n", *pInt);
    printf("실수형으로 사용 : %lf\n", *pDouble);

    printf("%s : 0x%p\n", pLiteral, pLiteral);
    printf("%d 힙메모리 : 0x%p\n", *pInt, pInt);
    printf("%c 지역변수 : 0x%p\n", LocalVariable, &LocalVariable);
    printf("%s : 0x%p\n", pArray, pArray);

    free(pInt); // 메모리 해제 malloc-free
    free(pDouble);

    return 0;

    // 메모리 누수, 메모리 침범
    //  몇 개인지 모를 때 동적할당 사용, 필요한 자료를 꺼내올때
}