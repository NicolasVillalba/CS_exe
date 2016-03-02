#include <stdio.h>
#define N 100

int main(){
    int A[N] = {0}, cnt = N, i, r = 0;
    while (cnt > 1) {
        for (i = 0; i < N; ++i) {
            if(A[i]) continue;
            if(++r == 3) {
                A[i] = 1;
                r = 0;
                --cnt;
                if(cnt == 1) break;
            }
        }
    }
    for (i = 0; i < N; ++i) {
        if(!A[i]) {
            printf("Id: %d\n", i);
            break;
        }
    }
    return 0;
}
