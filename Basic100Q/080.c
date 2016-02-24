#include<stdio.h>

#define N 3
#define M 3

void fun(int a[M][N], int n)
{
    for(int i = 1; i < M; i++)
        for(int j = 0; j < i; j++)
            a[i][j] *= n;
}

int main()
{
    int a[M][N] = {
        1,9,7,
        2,3,8,
        4,5,6
    };
    fun(a, 3);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
