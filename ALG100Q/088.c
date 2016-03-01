#include <stdio.h>
#define N 7
int main(){
    int n, i, j;
    for (i = 0; i < N; ++i) {
        scanf("%d", &n);
        for (j = 0; j < n; ++j) printf("*");
        printf("\n");
    }
    return 0;
}
