#include <stdio.h>
#define N 10

/*
  Compiled on Linux, not for Windows.
*/

char colors[][N] = {
    "\033[0m",
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[35m",
    "\033[36m"
};

int main(){
    int i = 0;
    char c;
    printf("Hello World!");
    while ((c = getchar()) && c != EOF) {
        if(c == '\n') continue;
        printf("%s", colors[++i]);
        printf("Hello World!");
        printf("%s\n", colors[0]);
        if(i >= 6) i = 0;
    }
    return 0;
}
