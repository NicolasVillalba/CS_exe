#include<stdio.h>

int fun(int a, int b)
{
    int a1 = a / 10, a2 = a % 10;
    int b1 = b / 10, b2 = b % 10;
    return (b2*1000 + a1*100 + b1*10 + a1);
}

int main()
{
    printf("Please input two integers betweent 10 and 99:\n");
    int a, b;
    scanf("%d %d", &a, &b);
    int ret = fun(a,b);
    printf("%d\n", ret);
    return 0;
}
