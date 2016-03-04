#include<stdio.h>

int main()
{
    int a = 100;
    short b = 100;
    long c = 1000;
    long long d = 101000;
    printf("sizeof(int) = %ld\n", sizeof(a));
    printf("sizeof(short) = %ld\n", sizeof(b));
    printf("sizeof(long) = %ld\n", sizeof(c));
    printf("sizeof(long long) = %ld\n", sizeof(d));
    return 0;
}
