#include<stdio.h>
#define n 10

void fun(int a[][n])
{
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            a[i][j] = 0;
}


int main()
{
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = 5;
    fun(a);
    for(int i = 0; i < n; i++)
    {
         for(int j = 0; j < n; j++) printf("%d ", a[i][j]);
         printf("\n");
    }
    return 0;
}
