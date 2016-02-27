#include <stdio.h>
#define N 10

void swap(int A[], int l, int r) {
    int t;
    while (l < r) {
        t = A[l];
        A[l] = A[r];
        A[r] = t;
        ++l; --r;
    }
} // void swap(int A[], int l, int r)

void fun(int A[], int m) {
    swap(A, 0, N - m - 1);
    swap(A, N - m, N - 1);
    swap(A, 0, N - 1);
} // void fun(int A[], int m)

int main(){
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, i;
    fun(A, 4);
    for (i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
