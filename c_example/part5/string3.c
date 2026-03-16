#include <stdio.h>
#include <string.h>

char *myStrcpy(char *pDes, const char *pSrc);

int main(void)
{
    char str2[200] = "strawberry";
    myStrcpy(str2, "apple");
    printf("%s\n", str2);
    myStrcpy(str2, "banana");
    printf("%s\n", str2);
    printf("%s\n", myStrcpy(str2, "pineapple"));

    return 0;
}

char *myStrcpy(char *pDes, const char *pSrc)
{
    char *pA = pDes;
    while (*pSrc != '\0') // = NULL
    {
        *pDes = *pSrc;
        pDes++; // 다음 칸으로
        pSrc++;
    }
    *pDes = '\0';
    return pA;
}