# dog2026

---

고려대 개발자 양성과정에서 쓰이는 저장소이다.
1. 프로그래머스
https://school.programmers.co.kr/learn/challenges/beginner?order=acceptance_desc&gad_source=1&gad_campaignid=22356298761&gbraid=0AAAAAC_c4nAWwCkxLSCDW0kAtv0ti-GPI&gclid=EAIaIQobChMI7rm47o2XkwMV5KdmAh1TrQD3EAAYASAAEgIpLvD_BwE\


# 2026.03.09

---

자기소개\
wsl 설치\
vscode, git 설치\
os 설명(리눅스, wsl2 사용하기로 함)\
vscode, github 연결 "git clone git 주소'\
~$ 유저의 홈 => cd ~\
주소 변경 cd, 리스트 ls, mkdir 새 폴더, nano 내용 수정, cat 파일 내용 확인, gcc 설치

hello world 프로그램 
- #includ  <stdio.h>, printf(");, type main(특별 지위, entry point)(파라미터)

literal 프로그램
- %d(10진법), %f, %c, %s, %x(16진수). %lld, %o(8진수)
> int d, char c, char* s, octal o, hex h, float f, double lf, long double ldf, long long ll, unsigned int u, unsigned long long llu, pointer p, string s

limit 프로그램 
- #define 
- int(정수), float/ double(소수), long double, long long, unsigned int, unsigned long long
- 상수 : constant
> 리터럴 문자열 상수(data 영역에 저장), 일반 상수(스택 영역), 숫자(123), 문자('A'), 문자열("바인드")
- 변수 : variable 
> 메모리 공간 선언 후 사용, 참조(printf("%d", number);, int number = 123;)\
 type 엄밀히, 미리 규칙을 정해두면 다른 타입 연산 가능
- cmake project, cmakelists.txt를 사용해 makefile만들고 make 명령어로 컴파일,cc 명령어 대신 사용 
> cc -o ~ ~ + 라이브러리 추가 + 분할컴파일(기능별로)
---

터미널에서 유저 정보 입력\
git config --global user.email dogyeng3610@gmail.com
git config --global user.name dogyeong3610-afk

wsl ID : dog014\
passward : rlaehrud

---

> wsl --install -d Ubuntu-22.04\
sudo apt install gcc\
sudo apt update\
sudo apt-get install gcc

# 2026.03.10

---
charNumber 프로그램
- & 주소 연산자
- scanf 문자 입력
> 변수를 불러올때 ${변수명}

makefile 생성
- make all, Target, make clean
> sudo apt install make
- make 명시하지 않았을 때는 첫번째 코드 인식
- makefile만 인식 ex) makefile_temp 인식x

stringcopy 프로그램
> #include <string.h>
- strcpy로 코드 간축
- 문자 뒤 NULL 인식
> 프로그램은 0부터 카운트

oddEven 프로그램
- 홀수는 참, 짝수는 거짓 나머지가 0이면 false
- if(T or F){}

compare 프로그램
> #include <strbool.h>
- bool은 true, false
- 관계연산자 ==
> printf("1 <= %d <= 9 : %s\n", num, (1 <= num && num <= 9)? "true": "false");
옳은 수식일 경우 true, 아니면 false

triangle 프로그램
- %lf, %af(a는 소수점자리까지 표현)

타입 캐스팅, fahr2Celcius, sizeof
increment
biletter
genderratio
alphabet

# 2026.03.11

if
- absoluteValue, passFail, passFail2, posZeroNeg, scoreGrade
- if(조건){}
- 조건? T:F
- if(조건){} else{}
- 입력받은 값을 1에 저장해서 출력
> #include <stdlib.h>\
 int score = atoi(argv[1]);
- if(조건){}else if(조건){} else{}
- 등급을 grade에 저장하는 if문 => grade 출력
> char grade = 'F';

switch
-scoreGradeswitch
- switch(조건){case숫자:/코드/break....default:/코드/break}
- case 뒤 무조건 숫자만 매칭

dice
- 난수 생성
>#include <stdlib.h> // 난수\
#include <time.h>   // 시간이나 전류값

>int main(void)\
{\
    int dice;\
    srand(time(NULL));     // 난수의 시드값을 현재 시간으로 설정\
    dice = rand() % 6 + 1; // 1부터 6까지의 난수 생성\
    printf("주사위의 숫자는 %d입니다.\n", dice);\
    return 0;\
}

for
- oneToTen, one2TenSum, a2bSum
- for(초기화, 조건, 증감식){코드}코드
- for문 안에서 선언하면 for문 안에서만 사용
>for (int i = 0; i < 10; ++i)\
    {\
        sum = sum + i + 1;\
    }
- 이중 for문 계층적

while
-while(조건문){코드}

do while
-do{코드}while{코드}

- continue 다음 루프로 이동
- break 블록 탈축(강제false)
변수
- 전역변수, 지역변수, 범위(scope)

array
- 변수명[타입의 묶음]
- [0,n) 0부터 n-1까지 접근 가능
- 선언과 대입 따로 가능
- 선언 + 초기화 가능 arr[5] = {0,1,2,3,4}
> int nums[5] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 2, 3, 4, 5};
    int nums3[10] = {1, 2, 3, 4, 5}; 
    int nums4[50];                   
    int nums5[50] = {0};
- 메모리 범위 내에서만

# 2026.03.12

localVariable
swap
selectionSorting
bubbleSorting
qsort

