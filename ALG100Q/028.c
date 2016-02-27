#include <stdio.h>

int fun(int n) {
    if(n == 1) return 10;
    else return fun(--n) + 2;
} // int fun(int n)


int main(){
    printf("%d\n", fun(5));
    return 0;
}
