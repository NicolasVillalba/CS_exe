#include<stdio.h>
#define n 10

double fun(int a[][n])
{
    int sum = 0;
    int cnt = 4*n - 4;
    for(int i = 1; i < n; i++)
    {
        sum += a[0][i];
        sum += a[i][0];
        sum += a[n-1][i];
        sum += a[i][n-1];
    }
    sum +=(a[0][0] + a[n-1][n-1] + a[0][n-1] + a[n-1][0]);
    double aver = sum /(1.0 * cnt);
    return aver;
}

int main()
{
     double s;
     int a[n][n];
     for(int i = 0; i < n; i++)
     {
          for(int j = 0; j < n; j++)
              a[i][j] = i*j;
     }
     s = fun(a);
     printf("the average number is %lf\n", s);
     return 0;
}
