#include <stdio.h>
#define N 5
typedef struct Student {
    char id[11];
    int score;
}Student;

int fun(Student s[], int n, Student b[]) {
    int avg = 0, i;
    for(i = 0; i < n; ++i) {
        avg += s[i].score;
    }
    avg /= n;
    int cnt = 0, min = 1000;
    for(i = 0; i < n; ++i) {
        if(s[i].score >= avg) {
            b[cnt++] = s[i];
        }
    }
    return cnt;
}

int main(){
    Student s[N] = {
        {"0001", 92},
        {"0002", 90},
        {"0003", 80},
        {"0004", 90},
        {"0005", 80},
    }, h[N];
    int cnt = fun(s, N, h), i;
    for(i = 0; i < cnt; ++i) {
        printf("id:%s\tscore:%d\n", h[i].id, h[i].score);
    }
    return 0;
}
