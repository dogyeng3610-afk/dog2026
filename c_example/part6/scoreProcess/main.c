#include "scoreProcess.h"

int main(void)
{
    char *finPath = "/home/dog014/dog2026/c_example/part6/scoreProcess/score.dat";
    char *foutPath = "/home/dog014/dog2026/c_example/part6/scoreProcess/score.out";
    FILE *fin = fopen(finPath, "r");
    FILE *fout = fopen(foutPath, "w");

    int n = count_students(fin);

    if (fin == NULL || fout == NULL)
    {
        fprintf(stderr, "파일을 열수 없습니다.\n");
        return 1;
    }

    Sdata *students = (Sdata *)malloc(sizeof(Sdata) * n);
    Sdata **table = (Sdata **)malloc(sizeof(Sdata) * n);

    if (students == NULL || table == NULL)
    {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    inputData(fin, students, n);
    calculateScore(students, n);
    calculateRank(students, n);
    sortPointers(students, table, n);
    printResult(fout, table, n);

    free(table);
    free(students);

    fclose(fin);
    fclose(fout);
    return 0;
}