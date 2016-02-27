#include <stdio.h>
#define N 100

void fun(int n) {
    if(!n) return;
    char c;
    c = getchar();
    fun(--n);
    putchar(c);
} // void fun(char *s)

int main(){
    fun(5);
    return 0;
}
