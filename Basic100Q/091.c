#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a/10, a2 = a%10;
    int b1 = b/10, b2 = b%10;
    return (a2*1000 + b2*100 + a1*10 +b1);
}

int main()
{
    printf("%d\n",fun(45, 12));
    return 0;
}
