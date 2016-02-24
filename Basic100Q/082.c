#include<stdio.h>
#define N 5

double fun(double a[])
{
    int sum = 0;
    double av = 0.0;
    for(int i = 0; i < N; i++)
        sum += a[i];
    av = sum*1.0 / N;
    return av;
}

int main()
{
    double a[N] = {90.5,72,80,61.5,55};
    double av = fun(a);
    printf("%0.1lf\n", av);
    return 0;
}
