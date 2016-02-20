#include<stdio.h>

float fun(double h)
{
    int a = (int)h;
    h -= (double)a;
    h *= 100;
    int b = (int)h;
    h -= (double)b;
    h *= 10;
    int c = (int)h;
    if(c >= 5) b += 1;
    float res = a*1.0 + b*1.0/100;
    return res;
}

int main()
{
    printf("Please input a double number:\n");
    double h;
    scanf("%lf",&h);
    float res = fun(h);
    printf("the result is %0.2lf\n", res);
    return 0;
}
