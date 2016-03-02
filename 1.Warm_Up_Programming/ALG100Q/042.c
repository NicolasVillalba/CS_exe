#include <stdio.h>

/*
  In C, variables are local by default,
  so there is actually no need to use auto;
*/

int main(){
    int i, j = 10;
    for (i = 0; i < 3; ++i) {
        auto int j = i;         /* Same effect as `int j = i;` */
        printf("%d\n", j);
    }
    printf("%d\n", j);
    return 0;
}
