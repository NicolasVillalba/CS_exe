#include<stdio.h>

unsigned fun(unsigned w)
{
    unsigned sum;
    if(w < 10) return 0;
    while(w > 10)
    {
        sum *= 10;
        sum += w%10;
        w /= 10;
    }
    return sum;
}

int main()
{
     unsigned n;
     printf("Please input a positive integer:\n");
     scanf("%d", &n);
     unsigned s = fun(n);
     printf("the result is %d\n", s);
     return 0;
}
