#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a / 10, a2 = a % 10;
    int b1 = b / 10, b2 = b % 10;
    return (a2*1000 + b1*100 + a1*10 + b2);
}

int main()
{
    int a, b;
    scanf("%d %d",&a, &b);
    int ret = fun(a, b);
    printf("%d\n", ret);
    return 0;
}
