#include <stdio.h>
#include <string.h>

int main()
{
    char fruit[20] = "strawberry";
    printf("딸기 :  %s\n", fruit);
    printf("딸기잼: %s %s\n", fruit, "jam");
    strcpy(fruit, "banana"); // 문자열 복사
    printf("바나나 : %s\n", fruit);
    // strcpy furit ->apple
    fruit[0] = 'a';
    fruit[1] = 'p';
    fruit[2] = 'p';
    fruit[3] = 'l';
    fruit[4] = 'e';
    fruit[5] = '\0'; // ='/0' 문자열의 끝을 알리는 null 문자

    printf("사과 : %s\n", fruit);
    return 0;
}