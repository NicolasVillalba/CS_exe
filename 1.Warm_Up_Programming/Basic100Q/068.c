#include<stdio.h>

double fun(int n)
{
    double sum = 1.0;
    for(int i = 1; i < n; i++)
    {
        int s = 1;
        for(int j = 1; j <= i ; j++)
            s *= j;
        sum += 1.0 / s;
    }
    return sum;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    double sum = fun(n);
    printf("%0.6lf\n", sum);
    return 0;
}
