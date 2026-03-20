#include "bowling.h"

static char board[7][50] = {
    "--------------------------------------------",
    "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |",
    "--------------------------------------------"
    "| | | | | | | | | | | | | | | | | | | | | |",
    "--------------------------------------------",
    "|   |   |   |   |   |   |   |   |   |     |",
    "--------------------------------------------"
};

void initScore(Score *player, const char name[])  //초기화
{
    // strcpy로 playername 저장
    // for문, 각 점수가 들어가는 칸에 0을 넣기
}
void playGame(Score *player, int i)
{
    // plyaer이름 출력
    
    // 점수입력 1cast
    // 몇번째 frame인지 출력
    // score check
    // setScore를 활용해 i번, 1, player
    
    // 점수 계산
    // calScore(player->frameScore, player->score)
    // player 출력
    
    // 스패어인가? 
    // if(((player->score[i-1][i-1])+(player->score[i-1][2]))== 10 && ((player->score[i-1][1] != 10)))
    // setFrameScore, printBoard 활용
    // 스트라이크인가?, 스패어 처리를 했는가?
    //if((player->score[i-2][1] == 10)&&(player->score[i-1][1]==1-))
    // setFrameScore, printBoard 활용
    // if(player->scoer[i][1]==10) return
    
    // 점수입력 2cast↑

    // 점수계산
    // calscore,printBoard 활용

    //합계가 10, 스패어처리 성공?
    // if((player->score[i-1][1])==10)
    // printf, setFrameScore, printBoard
    
    //,,
    // if((player->score[i][1]+player->score[i][2]) < 10 && (i>0))
    // printf, setFrameScore, printBoard
}
void playGame10Frame(Score *player)
{
    
    return;
}
void printBoard(Score *player)
{
    system("clear");
    printf("\nPlayer name:")
}
void setScore(int frame, int bow, Scoer *player)
{
    //board에 넣는 함수
    // 10점을 했는지 못했는지에 따라 바뀌기 때문에 스코어 초기화
    // 10째 스코어 초기화
    // 10일 때 x표시
    // 10 10 일 때  x표시
    // 스패어일 때 // char형태로int를 더해서 넣으면 char 정보를 넣을 있다. '0' + 1은 char 1
    // 0~9 사이의 점수일때
    // 3번째 던졌을 때
    // if else if else if else


}
void setFrameScore(int frame, Score *player)
{
    // 버퍼추가
    // sprintf 버프에 3개 넣음
    // strcpy를 사용해 5번 보드에 버프를 3개를 넣음
}
void calScore(int *frameScore, const int (*score)[3])
{
    // for 게임 11번 반복해 framescore초기화
    // for 11번 반복해  framescore와 이전점수, 모든 cast점수 더함
    // 스트라이크 보너스
    // if framscore와 이후 스코어 점수 합침
    // 스패어 했을 때 
    // else if

}