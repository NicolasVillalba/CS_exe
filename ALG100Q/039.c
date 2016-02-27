#include <stdio.h>

void insert(int A[], int sz, int n) {
    if(n > A[sz - 1]) {
        A[sz] = n;
        return;
    }

    int i = sz - 1;
    while (A[i] > n) {
        A[i + 1] = A[i];
        --i;
    }
    A[i + 1] = n;
}

int main(){
    int A[10] = {1, 2, 3, 5, 6, 7}, i;

    insert(A, 6, 4);

    for (i = 0; i < 7; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
