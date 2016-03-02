#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int main(){
    int a = 10, b = 20, c = 30;

    printf("MAX:%d\n", MAX(MAX(a, b), MAX(b, c)));
    printf("MIN:%d\n", MIN(MIN(a, b), MIN(b, c)));
    return 0;
}
