#include <stdio.h>
#define N 3
int main(){
    int M[N][N], i, j, a = 0;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", &M[i][j]);
        }
    }
    for (i = 0; i < N; ++i) {
        a += M[i][i];
    }
    a += M[0][2] + M[2][0];
    printf("%d\n", a);
    return 0;
}
