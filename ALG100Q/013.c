#include<stdio.h>

int main()
{
    for(int i = 100; i < 1000; i++)
    {
        int a = i/100;
        int b = i/10%10;
        int c = i%10;
        if((a*a*a + b*b*b +c*c*c) == i)
            printf("%d\n", i);
    }
    return 0;
}
