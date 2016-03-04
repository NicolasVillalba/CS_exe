#include<stdio.h>

int main()
{
    short a, b;
    a = 32767;
    b = a + 1;
    printf("a = %ld\n", sizeof(a));
    printf("b = %d\n", b);
    return 0;
}
