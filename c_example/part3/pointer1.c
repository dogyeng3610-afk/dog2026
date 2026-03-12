#include <stdio.h>

int main(void)
{
    int *p; // 주소값을 저장하는 변수 선언
    int Value;
    p = &Value;                                                     // Value의 주소값 p에 저장 p는 Value의 주소값
    *p = 200;                                                       /* 포인터 p가 가리키는 위치에 저장한다는 의미, p가 가리키는 위치는 &Value
                                                                     *p = 200 == Value = 200*/
    printf("포인터의 주소는 %p이고, 가리키는 값은 %d이다.", p, *p); // p는 Value의 주소값, *p는 주소가 가리키는 값
    return 0;
}
