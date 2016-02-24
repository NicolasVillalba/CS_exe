#include<stdio.h>

double fun(int n)
{
    double sum = 0.0;
    for(int i = 1; i <= n; i++)
        sum += 1.0/(i*(i+1));
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    double sum = fun(n);
    printf("%0.6lf\n", sum);
    return 0;
}
