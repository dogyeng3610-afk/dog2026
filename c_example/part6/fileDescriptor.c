#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char *path = "/home/dog014/dog2026/c_example/part6/";
    char fPath[100];
    sprintf(fPath, "%s%s", path, "test.dat");
    fd = open(fPath, O_WRONLY | O_CREAT | O_TRUNC, 0644); // 10,100,1000 |:비트 연산자 0644: 6쓰고 읽기만 가능,4read만 가능
    if (fd == -1)
        printf("파일을 열수 없다.\n");
    write(fd, "이것은 파일로 저장되는 예시 데이터 입니다.!", 62);
    close(fd);
    return 0;
    // 버퍼 없이 작동, 데이터 손실 가능성
}