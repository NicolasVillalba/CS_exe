#include<stdio.h>
#define M 3
#define N 4

void fun(int a[M][N], int b[M*N])
{
    int n = 0;
    for(int i = 0; i< M; i++)
        for(int j = 0; j < N; j++)
            b[n++] = a[i][j];
}

int main()
{
    int a[M][N] = {
        33,33,33,33,
        44,44,44,44,
        55,55,55,55
    };
    int b[M*N];
    fun(a, b);
    for(int i = 0; i < M*N; i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}
