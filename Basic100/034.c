//本题参考大神代码
#include <stdio.h>
#define N 5

typedef struct Student{
    int id, score;
}Student;

int fun(Student s[], int n, Student h[]) {
    int i, highest, cnt = 0;
    for(i = 0; i < n; ++i) {
        if(highest < s[i].score) {
            highest = s[i].score;
            h[0] = s[i];
            cnt = 1;
        } else if(highest == s[i].score) {
            h[cnt++] = s[i];
        }
    }
    return cnt;
}

int main(){
    Student h[N], s[N] = {
        {1, 60}, {2, 70}, {3, 80},
        {4, 90}, {5, 90},
    };
    int cnt, i;
    cnt = fun(s, N, h);
    for(i = 0; i < cnt; ++i) {
        printf("ID: %d\tScore: %d\n", h[i].id, h[i].score);
    }
    return 0;
}
