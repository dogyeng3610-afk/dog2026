#include <stdio.h>

int main(void)
{
    int num;
    printf("숫자를 넣으세요:\n");
    scanf("%d", &num);

    if (num > 0)
    {
        printf("%d는 양수입니다.\n", num);
    }
    else if (num == 0)
    {
        printf("%d는 0입니다.\n", num);
    }
    else
    {
        printf("%d는 음수입니다.\n", num);
    }
    return 0;
}