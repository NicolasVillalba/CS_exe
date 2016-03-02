#include <stdio.h>
#define M 3
#define N 3

void fun(int a[][N], int m) {
    int i, j;
    for(i = 0; i < M - 1; ++i) {
        for(j = i + 1; j < N; ++j) {
            a[i][j] *= m;
        }
    }
}

int main(){
    int A[M][N] = {
        1, 4, 7,
        2, 5, 8,
        3, 6, 9
    };
    fun(A, 2);
    int i, j;
    for(i = 0; i < M; ++i) {
        for(j = 0; j < N; ++j) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
