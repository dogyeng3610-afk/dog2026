#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;

int main(void)
{
    Book *pBook;
    int size;
    printf("넣을 데이터의 크기를 알려주세요:");
    scanf("%d", &size);
    pBook = (Book *)malloc(sizeof(Book) * size);
    if(pBook == NULL)
    {
        printf("메모리 할당에 실패했습니다.");
        exit(-1); // 현재 상태를 말함 //프로그램 내 프로그램 실행. 메타프로그램 자식 프로그램의 상태를 말함
    }

    for (int i = 0; i < size; ++i)
    {
        (pBook + i)->bookid = rand() % 1001;
        strcpy((pBook + i)->bookname, "책이름");
        strcpy((pBook + i)->publisher, "출판사");
        (pBook + i)->price = rand() % 1001 + 10000;
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%d %s %s %d\n", (pBook + i)->bookid, (pBook + i)->bookname, (pBook + i)->publisher, (pBook + i)->price);
    }
    free(pBook);
    return 0;
}