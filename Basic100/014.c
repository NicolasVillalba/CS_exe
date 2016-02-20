#include<stdio.h>
#define n 10

int fun(int a[n][n])
{
    int sum = 0;
    for(int i = 1; i < n-1; i++)
    {
        sum += a[0][i];
        sum += a[i][0];
        sum += a[n-1][i];
        sum += a[i][n-1];
    }
    sum += (a[0][0] + a[n-1][n-1] + a[0][n-1] + a[n-1][0]);
    return sum;
}

int main()
{
     int a[n][n];
     for(int i = 0; i < n; i++)
         for(int j = 0; j < n; j++)
             a[i][j] = i+j;
     int sum = fun(a);
     printf("the sum is %d\n", sum);
     return 0;
}
