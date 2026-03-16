// ./structArray < address.dat 데이터 파일
#include <stdio.h>

typedef struct
{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
} Address;

void printList(const Address *pList);
void inputList(Address *pList);
int main(void)
{
    // Address list[5] = {
    //     {.name = "홍길동", .age = 23, .tel = "111-1111", .addr = "울릉도 독도"},
    //     {"이순신", 35, "222-2222", "서울 건천동"},
    //     {"장보고", 19, "333-3333", "완도 청해진"},
    //     {"유관순", 15, "444-4444", "충남 천안"},
    //     {"안중근", 45, "555-5555", "황해도 해주"},
    // };
    Address list[5];
    inputList(list);
    printList(list); // 능동적으로 데이터 개수 변화가 없음
    return 0;
}

void printList(const Address *pList)
{
    int i;
    for (i = 0; i < 5; ++i)
    {
        printf("%10s%5d%15s%20s\n", (pList + i)->name, (pList + i)->age, (pList + i)->tel, (pList + i)->addr); // 배열 정의 없음 plist[]형태 x
        // 구조체로 넘어가면 포인터 형식으로 사용 (pList + i)
    }
}

void inputList(Address *pList)
{
    for (int i = 0; i < 5; ++i)
    {
        scanf("%s %d %s %s", (pList + i)->name, &(pList + i)->age, (pList + i)->tel, (pList + i)->addr);
    }
}