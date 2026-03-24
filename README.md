# dog2026

---

고려대 개발자 양성과정에서 쓰이는 저장소이다.
1. 프로그래머스
https://school.programmers.co.kr/learn/challenges/beginner?order=acceptance_desc&gad_source=1&gad_campaignid=22356298761&gbraid=0AAAAAC_c4nAWwCkxLSCDW0kAtv0ti-GPI&gclid=EAIaIQobChMI7rm47o2XkwMV5KdmAh1TrQD3EAAYASAAEgIpLvD_BwE\


# 2026.03.09

---

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
- 전역변수-최상위, 지역변수, 사용 범위(scope)

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

함수
- type 식별자(argument-type 변수명); 선언
- type 식별자(argument-type 변수명){} 정의
- 데이터 복사 메모리 사용 증가 주의
- 포인터 넘기기를 통해 데이터 복사
- type = return type
- return 값 없으면 void
- localVariable
- swap
>void swap(int *a, int *b)\
{\
    int temp;\
    temp = *a;\
    *a = *b;\
    *b = temp;\
}\
void info(int a, int b)\
{\
    printf("a: %d, b: %d\n", a, b);\
}


정렬
1) 선택정렬 selectionSorting
- 기준을 잡고 다른 인덱스와 비교
- 0 vs 1, 0 vs 2, 0 vs 3...
2) 버블정렬 bubbleSorting
- 순차적으로 두 개씩 비교 
- 0 vs 1. 1 vs 2...
3) qsort
- qsort(배열, 타입-숫자, 원소의 사이즈(int = 4/sizeof연산자), 비교하는 함수의 타입)
- 데이터가 클수록 용이
 > int compare(const void *a, const void *b);\
qsort(nums, indexN, sizeof(int), compare);\
int compare(const void *a, const void *b)\
{\
return (*(int *)a - *(int *)b); \
}

포인터pointer
- pointer1
- 포인터 p가 가리키는 위치에 저장, p가 가리키는 위치는 &Value
> int *p;\
*주소값을 저장하는 변수 선언*\
int Value;\
p = &Value;\
*Value의 주소값 p에 저장 p는 Value의 주소값*\
*p = 200;\
*p = 200 == Value = 200*

이중포인터
- pointer4_doublepointer


다른 타입 포인터 가져오기
- pointer3
- Big endian, Little endian


함수명 = 포인터
- int 함수명(type, type);
- int (*포인터)(type,type);
> 포인터 = 함수명;\
fp = add;
>int 변수 = 함수(숫자, 숫자)\
int re = fp(4,3)
- pointer5_functionpointer

void * void 포인터
- pointer6_voidpoint


배열명 - 포인터
- pointerAndArray
- arrayAssignment
- arraycompare


새 파일 CMakeLists.txt
새 파일 .gitignore
> browse.*\
  build/

# 2026.03.13
  ## 분할 컴파일
  
  ## prat4 carSerial, myRandom
  - 폴더 생성 - 파일 생성(CMakeLists.txt, main.c, lib.h, lib.c)
  ### CMakeLists.txt
  - 최상위 cmake파일
  - 파일 주소 들어가야함.
  > cmake_minimum_required(VERSION 3.10)\
    project(dog2026)\
    set(CMAKE_CXX_STANDARD 17)\
    set(CMAKE_C_STANDARD 17)\
    add_subdirectory(c_example/part3)\
    add_subdirectory(c_example/part4/carSerial)\
    project(~)\
    add_subdirectory(c_example/part4/myRandom)
  ### 폴더 내 CMakeLists.txt
  - 폴더명, main, lib.c파일 들어가야함.
  > cmake_minimum_required(VERSION 3.10)\
    include_directories(${CMAKE_CURRENT_LIST_DIR})\
    add_executable(~ main.c ~.c)
  ### 빌드 방법
  #### 1. cmake로 빌드
  > 터미널\
    cd ~\
  > cc -c main.c\
    mkdir build\
    cd build\
    cmake ..\
    make
  #### 2. makefile로 빌드
  ##### 터미널
    cc -c serial.c\
    cc -o carSerial main.o serial.o
    
  ###### make파일
  > carSerial : main.o serial.o\
	cc -o carSerial main.o serial.o\
    main.o : main.c serial.h\
	cc -c main.c\
    serial.o : serial.c serial.h\
	cc -c serial.c\
    clean :\
	rm main.o serial.o carSerial

  # 2026.03.16
  ## 구조체
  - struct : 사용자 정의 타입
  - typedef A B : 별명붙이기 (가독성 ↑)
  - 멤버 연산자 ., ->
  >   struct date\
  {\
    int year;\
    int month;\
    int day;\
  };\
  >>struct data d;

  > typedef struct\
  {\
    int year;\
    int month;\
    int day;\
  } Date;\
  >> Date d;

  > 대소문자 구분 : 식별자, 함수명, 변수명 모두 소문자\
  사용자 정의 타입만 대문자
  

  내부에서 읽기만 한다면 const 사용
  연산자의 우선순위

  #progma once


## union, enum, string

# 2026.03.17

# 2026.03.18
## Data structure
### List
### Queue
### Stack

# 2026.03.19
## 네트워크
- HTTP : www.~
- 소켓 통신 - 버퍼(레지스트리) => TCP/IP, UDP/IP => port
- WAN, LAN
- MQTT 


# 2026.03.20


# 2026.03.23
### 1. 하드웨어 관련 핵심 용어
* MCU (Micro Controller Unit): CPU, 메모리, I/O 포트 등을 하나의 칩에 모아놓은 '단일 칩 컴퓨터'입니다. 기기 제어가 주 목적입니다.
* RISC (Reduced Instruction Set Computer): 명령어를 최소화하여 단순하게 만든 CPU 구조입니다. 명령어가 단순해서 처리 속도가 매우 빠릅니다.
* 하버드 아키텍처 (Harvard Architecture): 프로그램이 저장되는 공간과 데이터가 저장되는 공간의 통로(버스)를 분리한 구조입니다. 동시에 접근이 가능해 속도가 빠릅니다.
* 레지스터 (Register): CPU 내부에 있는 아주 빠른 임시 저장 공간입니다. 연산의 중간 결과나 상태를 저장합니다.
* I/O 포트 (Input/Output Port): MCU가 외부 소자(LED, 스위치, 센서 등)와 데이터를 주고받는 통로입니다.

### 2. 메모리 관련 용어
* Flash Memory (플래시 메모리): 우리가 작성한 **프로그램 코드**가 저장되는 곳입니다. 전원이 꺼져도 데이터가 지워지지 않습니다(비휘발성).
* SRAM (Static RAM): 프로그램 실행 중에 발생하는 **임시 데이터**를 저장합니다. 속도는 빠르지만 전원이 꺼지면 데이터가 사라집니다(휘발성).
* EEPROM: 전원이 꺼져도 유지되어야 하는 **설정값이나 비밀번호** 등을 저장할 때 주로 사용합니다.

### 3. 개발 및 프로그래밍 용어
* 컴파일러 (Compiler): 사람이 작성한 C언어 코드를 MCU가 이해할 수 있는 기계어(0과 1)로 번역해주는 도구입니다.
* IDE (Integrated Development Environment): 통합 개발 환경. 코드 작성, 컴파일, 업로드를 하나의 프로그램 안에서 할 수 있게 만든 소프트웨어입니다. (예: Atmel Studio)
* ISP (In-System Programming): 칩을 보드에서 떼어내지 않고도 전선만 연결해 내부 메모리에 프로그램을 적재(Download)하는 방식입니다.
* HEX 파일: 컴파일 결과물로 나오는 실행 파일입니다. 실제 MCU의 플래시 메모리에 들어가는 데이터 형태입니다.

### 4. 시스템 제어 용어
* 클럭 (Clock): MCU의 심장 박동과 같습니다. 이 신호에 맞춰 모든 회로가 동작하며, 속도가 빠를수록 초당 처리 능력이 높습니다.
* ADC (Analog-to-Digital Converter): 센서의 아날로그 신호(전압)를 MCU가 이해할 수 있는 디지털 숫자 값으로 변환해주는 장치입니다.
* USART (Universal Synchronous/Asynchronous Receiver/Transmitter): 직렬(시리얼) 통신의 한 종류로, PC나 다른 기기와 데이터를 주고받을 때 사용합니다.
* 인터럽트 (Interrupt): 프로그램 실행 중 긴급한 상황이 발생했을 때, 하던 일을 잠시 멈추고 우선순위가 높은 일을 먼저 처리하는 기능입니다.

---

### 1. 마이크로 컨트롤러(MCU)의 이해
* 정의: 마이크로 프로세서(CPU)에 메모리와 각종 주변장치(I/O 포트 등)를 하나의 칩에 집적한 '단일 칩 컴퓨터'입니다.
* 특징: 주변 하드웨어 제어 능력이 강화되어 있으며, 제품의 소형화, 저가격화, 고신뢰성을 가능하게 합니다.
* 응용 분야: 가전제품(세탁기, 전자레인지), 자동차(엔진 제어), 통신 기기(휴대폰), 산업용 로봇 등 매우 광범위합니다.

### 2. AVR 마이크로 컨트롤러의 특징
* 탄생: 1997년 ATMEL사에서 발표한 8비트 RISC 구조의 마이크로 컨트롤러입니다.
* RISC 구조: 명령 세트를 축소하여 실행 속도를 높였으며, 1MHz당 1MIPS의 빠른 처리 속도를 자랑합니다.
* 하버드 아키텍처: 프로그램 메모리와 데이터 메모리의 버스가 분리되어 있어 처리가 효율적입니다.
* 편의성: 칩 내부에서 직접 프로그램을 내려받는 **ISP(In System Programming)** 기능을 지원합니다.

### 3. ATMega128A의 주요 사양 및 구조
메모리 구성:
* 플래시 메모리 (128KB): 프로그램 코드가 저장되는 비휘발성 메모리입니다.
* SRAM (4KB): 프로그램 실행 중 발생하는 임시 데이터를 저장합니다.
* EEPROM (4KB): 전원이 꺼져도 보존해야 할 설정값 등을 저장합니다.
* 입출력 포트: 총 53개의 프로그램 가능한 I/O 핀을 제공하며, 포트 A~G까지 존재합니다.

### 4. 핀(Pin) 기능 및 외부 인터페이스
주요 제어 핀:
* RESET: 시스템 리셋 신호.
* XTAL1, XTAL2: 외부 크리스탈 등을 연결하는 발진용 단자.
* AVCC, AREF: AD 변환기를 위한 전원 및 참조 전압 단자.
* 포트 기능 확장: 포트 A와 C는 외부 메모리를 연결할 때 주소 및 데이터 버스로 사용될 수 있습니다.

### 5. 동작 모드 및 시스템 관리
* 클럭 시스템: 내부 RC 발진기, 외부 수정 발진기 등 5가지 소스에서 클럭을 공급받을 수 있습니다.
* 슬립 모드(Sleep Mode): 전력 소비를 줄이기 위해 Idle, Power-down 등 6가지 저전력 모드를 지원합니다.
* 리셋 발생원: 파워 온 리셋, 외부 리셋, 워치독 리셋 등 5가지 상황에서 시스템 초기화가 일어납니다.

---
# 2026.3.24
## 