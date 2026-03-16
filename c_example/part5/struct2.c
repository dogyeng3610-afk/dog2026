#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
} Date;

int main(void)
{
    Date d;
    Date *pD;
    d.year = 2026;
    d.month = 7;
    d.day = 19;

    Date d2={
        .year = 2026,
        .month = 7,
        .day = 19};

        // 구조체 선언 후 초기화

    pD = &d;
    printf("%d-%d-%d", d.year, d.month, d.day);
    // printf("%d-%d-%d", (*pD).year, (*pD).month, (*pD).day);
    // printf("%d-%d-%d", pD->year, pD->month, pD->day);

    return 0;
}