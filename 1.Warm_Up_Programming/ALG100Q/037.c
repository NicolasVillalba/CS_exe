#include <stdio.h>
#define N 10

void sort(int A[], int n) {
    int i, j, t;
    for (i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            if(A[j] < A[i]) {
                t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

int main(){
    int A[N] = {9, 1, 5, 6, 0, 7, 2, 3, 4, 8}, i;
    sort(A, N);
    for (i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
