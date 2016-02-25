#include<stdio.h>
#include<math.h>

int main()
{
    for(long i = 1; i < 100000; i++)
    {
        long a = sqrt(i + 100);
        long b = sqrt(i + 100 + 168);
        if(a*a == i+100 && b*b == i + 268)
            printf("%ld\n", i);
    }
    return 0;
}
