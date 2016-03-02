#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a / 10, a2 = a % 10;
    int b1 = b / 10, b2 = b % 10;
    return (b2*1000 + a2*100 + b1*10 + a1);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int s = fun(a, b);
    printf("%d\n",s);
    return 0;
}
