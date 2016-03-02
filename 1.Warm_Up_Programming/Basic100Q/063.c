#include<stdio.h>

int fun(int n)
{
    int sum = 0;
    for(int i = 2; i < n; i++)
        if(n % i == 0) sum += i;
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = fun(n);
    printf("sum = %d\n", sum);
    return 0;
}
