#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d + %d = %d", a, b, a + b);
    return 0;
}
