#include <stdio.h>

int main(){
    int a = 077, b;
    b = a & 007;

    printf("a: %o\n", a);
    printf("b: %o\n", b);
    return 0;
}