#include<stdio.h>
#define N 3
#define M 3

void fun(int a[N][M], int b[N][M])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            b[i][j] = a[i][j] + a[j][i];
}

int main()
{
    int a[N][M] = {
         1,2,3,
         4,5,6,
         7,8,9
    };
    int b[N][M];
    fun(a, b);
    for(int i = 0; i < N; i++)
    {
         for(int j = 0; j < M; j++)
             printf("%d ", b[i][j]);
         printf("\n");
    }
    return 0;
}
