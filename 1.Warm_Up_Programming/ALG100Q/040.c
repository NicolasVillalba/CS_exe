#include <stdio.h>

void swapArray(int A[], int l, int r) {
    int t;
    while (l < r) {
        t = A[l];
        A[l] = A[r];
        A[r] = t;
        ++l;
        --r;
    }
}

int main(){
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, i;
    swapArray(A, 0, 9);
    for (i = 0; i < 10; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
