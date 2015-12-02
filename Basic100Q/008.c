#include<stdio.h>


float fun(int n)
{
   float sum = 0.0;
    int stmp = 0;
    for(int i = 1; i <= n; i++)
    {
        stmp += i;
        sum += 1/stmp;
    }
    return sum;
}

int main()
{
    printf("Please input n:\n");
    int n = 0;
    scanf("%d", &n);
   float sum = fun(n);
    printf("The result is %lf\n", sum);
    return 0;
}
