#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[10];
    int score[10][3] = {0}; // 프레임별 점수 저장
    int rolls[21] = {0};    // 전체 투구 저장 (보너스 계산용)
    int sum[10] = {0};      // 누적 점수
    int rollIndex = 0;      // rolls 배열 인덱스

    printf("볼링 게임을 시작합니다.\n플레이어 이름을 입력하세요(최대 9글자) :\n");
    scanf("%9s", name);

    // ===== 10프레임 진행 =====
    for (int i = 0; i < 10; ++i)
    {
        // ===== 보드 출력 =====
        printf("\nPlayer name: %s\n", name);
        printf("-------------------------------------------\n");
        printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  |\n");
        printf("-------------------------------------------\n|");

        // 점수판 출력 (X, / 포함)
        for (int k = 0; k < 10; ++k)
        {
            if (k < i)
            {
                // 스트라이크
                if (score[k][0] == 10)
                    printf("X | ");
                // 스페어
                else if (score[k][0] + score[k][1] == 10)
                    printf("%d/| ", score[k][0]);
                // 일반
                else
                    printf("%d%d| ", score[k][0], score[k][1]);
            }
            else
            {
                printf("  | ");
            }
        }

        printf("\n-------------------------------------------\n|");

        // ===== 누적 점수 계산 =====
        int tempScore = 0;
        int idx = 0;

        for (int f = 0; f < 10; f++)
        {
            if (f < i)
            {
                // 스트라이크
                if (rolls[idx] == 10)
                {
                    tempScore += 10 + rolls[idx + 1] + rolls[idx + 2];
                    printf("%3d|", tempScore);
                    idx++;
                }
                // 스페어
                else if (rolls[idx] + rolls[idx + 1] == 10)
                {
                    tempScore += 10 + rolls[idx + 2];
                    printf("%3d|", tempScore);
                    idx += 2;
                }
                // 일반
                else
                {
                    tempScore += rolls[idx] + rolls[idx + 1];
                    printf("%3d|", tempScore);
                    idx += 2;
                }
            }
            else
            {
                printf("   |");
            }
        }

        printf("\n-------------------------------------------\n");

        // ===== 1차 투구 =====
        printf("%d frame 1 cast : ", i + 1);
        scanf("%d", &score[i][0]);
        rolls[rollIndex++] = score[i][0];

        // ===== 스트라이크 =====
        if (score[i][0] == 10)
        {
            continue;
        }

        // ===== 2차 투구 =====
        printf("%d frame 2 cast : ", i + 1);
        scanf("%d", &score[i][1]);

        // 입력 제한
        while (score[i][0] + score[i][1] > 10)
        {
            printf("유효한 점수를 입력하세요 (0-%d): ", 10 - score[i][0]);
            scanf("%d", &score[i][1]);
        }

        rolls[rollIndex++] = score[i][1];

        // ===== 10프레임 보너스 =====
        if (i == 9)
        {
            // 스트라이크 or 스페어면 보너스
            if (score[i][0] == 10 || score[i][0] + score[i][1] == 10)
            {
                printf("10 frame bonus cast : ");
                scanf("%d", &score[i][2]);
                rolls[rollIndex++] = score[i][2];
            }
        }
    }

    // ===== 최종 점수 계산 =====
    int finalScore = 0;
    int idx = 0;

    for (int frame = 0; frame < 10; frame++)
    {
        // 스트라이크
        if (rolls[idx] == 10)
        {
            finalScore += 10 + rolls[idx + 1] + rolls[idx + 2];
            idx++;
        }
        // 스페어
        else if (rolls[idx] + rolls[idx + 1] == 10)
        {
            finalScore += 10 + rolls[idx + 2];
            idx += 2;
        }
        // 일반
        else
        {
            finalScore += rolls[idx] + rolls[idx + 1];
            idx += 2;
        }
    }

    printf("\n게임이 종료되었습니다!\n");
    printf("최종 점수: %d\n", finalScore);

    return 0;
}