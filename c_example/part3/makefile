SRCS   = $(wildcard *.c)          # 현재 디렉토리의 모든 .c 파일을 SRCS 변수에 저장
TARGET = $(SRCS:.c=)              # .c를 제거한 이름으로 타겟 설정

all : $(TARGET)

clean :
	rm $(TARGET)