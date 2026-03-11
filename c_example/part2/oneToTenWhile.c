#include <stdio.h>

int main(void)
{
    int i = 1;
    while (i <= 10)
    {
        printf("%d ", i);
        ++i;
    }

    printf("%d\n", i);
    return 0;
}