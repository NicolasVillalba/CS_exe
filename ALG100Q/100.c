#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct {
    char num[6];
    char name[8];
    int score[3];
    float avg;
}Student;

int main(){
    FILE *fp = fopen("stud", "w");
    if(fp == NULL) {
        fprintf(stderr, "cannot open stud.\n");
        exit(0);
    }

    Student students[N];
    int i, j;
    for (i = 0; i < N; ++i) {
        printf("ID, Name, Score:\n");
        scanf("%s %s %d %d %d", students[i].num, students[i].name,
              &students[i].score[0], &students[i].score[1],
              &students[i].score[2]);
    }

    int totalScore;
    for (i = 0; i < N; ++i) {
        totalScore = 0;
        for (j = 0; j < 3; ++j) totalScore += students[i].score[i];

        students[i].avg = totalScore / 3.0;
    }

    for (i = 0; i < N; ++i) {
        fprintf(fp, "ID:%s\nName:%s\nScore:",
                students[i].num, students[i].name);

        for (j = 0; j < 3; ++j)
            fprintf(fp, "%d ", students[i].score[j]);

        fprintf(fp, "\nAvg:%.2f\n", students[i].avg);
    }
    return 0;
}
