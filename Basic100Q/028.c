#include <stdio.h>
#include <string.h>

#define N 5

void fun(int x[], int n, int *max, int *index) {
    int i;
    *max = 1 << 31;
    *index = -1;
    for(i = 0; i < n; ++i) {
        if(x[i] > *max) {
            *max = x[i];
            *index = i;
        }
    }
}

int main(){
    int x[N] = {0, 1, 2, 3, 4}, max, index;
    fun(x, N, &max, &index);
    printf("A[%d]: %d\n", index, max);
    return 0;
}
