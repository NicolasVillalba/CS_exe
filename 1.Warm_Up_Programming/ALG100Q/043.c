#include <stdio.h>

int main(){
    int i, j = 10;
    for (i = 0; i < 3; ++i) {
        /* static int j = i; */
        static int j = 1;
        printf("%d\n", j);
    }
    printf("%d\n", j);
    return 0;
}
