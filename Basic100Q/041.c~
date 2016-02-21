//参考大神代码
#include <stdio.h>
#define M 3
#define N 3

void fun(int A[M][N], char *s) {
    int i, j, cnt = 0;
    for(j = 0; j < N; ++j) {
        for(i = 0; i < M; ++i) {
            s[cnt++] = A[i][j] + '0';
        }
    }
    s[cnt] = '\0';
}

int main(){
    int A[M][N] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    char s[M * N + 1];
    fun(A, s);
    printf("%s\n", s);
    return 0;
}
