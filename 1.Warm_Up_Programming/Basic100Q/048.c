#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a / 10;
    int a2 = a % 10;

    int b1 = b / 10;
    int b2 = b % 10;
    int c = a1*1000 + a2*10 + b1*100 + b2;
    return c;
}

int main()
{
     int a = 88, b =45;
     printf("a = %d, b = %d\n", a, b);
     int c = fun(a, b);
     printf("c = %d\n", c);
     return 0;
}
