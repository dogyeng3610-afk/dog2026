#include "date.h"

void printDate(const Date *pDate)
{
    printf("%d/%d/%d", pDate->year, pDate->month, pDate->day);
}

void setDate(Date *pDate, const int year, const int month, const int day) // 내부에서 변함 대입만하고 변하지 않음
{
    pDate->year = year;
    pDate->month = month;
    pDate->day = day;
}