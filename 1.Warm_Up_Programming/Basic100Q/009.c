#include<stdio.h>

double fun(int m, int n)
{
    if(m <= n) return 0.0;
    int sum_m = 0, sum_n = 0, sum = 0;
    for(int i = 1, j = 1, k = 1; i <= m, j <= n, k <= (m - n); i++,j++,k++)
    {
        sum_m += i;
        sum_n += j;
        sum += k;
    }
    double p = 0.0;
    p = sum_m/(sum_n * sum);
    return p;
}

int main()
{
     int m,n;
     printf("Please input the m,n:\n");
     scanf("%d,%d",&m,&n);
     double res = fun(m,n);
     printf("The result is %lf\n", res);
    return 0;
}
