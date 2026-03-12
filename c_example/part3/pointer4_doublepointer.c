// 이중포인터
#include <stdio.h>

int main(void)
{
    int var_a;
    int *pVar_a;
    int **ppVar_a;

    var_a = 100;
    pVar_a = &var_a; 
    ppVar_a = &pVar_a;

    **ppVar_a = 200;
    printf("var_a: %d, &var_a: %p\n", var_a, &var_a);
    printf("pvar_a: %p, *pvar_a: %d\n", pVar_a, *pVar_a);
    printf("ppvar_a: %p, *ppvar_a: %p, **ppVar_a: %d\n", ppVar_a, *ppVar_a, **ppVar_a);

    return 0;
}
