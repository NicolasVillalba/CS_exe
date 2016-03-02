#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a/10, a2 = a%10;
    int b1 = b/10, b2 = b%10;
    return (a1*1000 + b2*100 + a2*10 + b1);
}

int main()
{
    int s = fun(45, 12);
    printf("%d\n", s);
    return 0;
}

