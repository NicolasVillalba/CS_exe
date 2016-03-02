#include<stdio.h>


int fun(int t)
{
    int a = 0, b = 1, tmp;
    while(a + b <= t)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    return a + b;
}

int main()
{
     printf("%d\n", fun(40));
     return 0;
}
