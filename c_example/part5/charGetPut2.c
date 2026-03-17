#include <stdio.h>
#include <string.h>

int main(void)
{
    char string1[100];
    printf("문자열을 넣으시요. : \n");
    // gets -> NULL이 있을 때까지 받음, 지금 사용x 보안이슈
    fgets(string1, 10, stdin); // ?개까지 받음
    printf("%s", string1);
    printf("문자열을 넣으시오 : \n");
    scanf("%s", string1);
    // fscanf(stdin, "%s", string1); 다른 파일로 넘길 때 사용
    printf("%s", string1);

    return 0;
}