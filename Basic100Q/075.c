#include<stdio.h>
#define M 3
#define N 4

void fun(int a[M][N], int t[M*N])
{
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            t[cnt++] = a[j][i];
    }
}

int main()
{
    int a[M][N] = {
         33,33,33,33,
         44,44,44,44,
         55,55,55,55
    };
    int t[M*N];
    fun(a, t);
    for(int i = 0; i < M*N; i++)
        printf("%d ", t[i]);
    printf("\n");
    return 0;
}

