#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a/10, a2 = a%10;
    int b1 = b/10, b2 = b%10;
    return (b1*1000 + a2*100 + b2*10 + b2);
}

int main()
{
    int s = fun(45, 12);
    printf("%d\n", s);
    return 0;
}
