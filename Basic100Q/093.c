#include<stdio.h>
#include<math.h>

double fun(int n, double x)
{
    double sum = 1.0;
    int deno = 1;
    for(int i = 1; i <= n; i++)
    {
        deno *= i;
        sum += (double)pow(x,i) / deno;
    }
    return sum;
}

int main()
{
     printf("%.6lf\n", fun(10, 0.3));
     return 0;
}


