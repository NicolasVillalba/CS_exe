#include <stdio.h>
#define N 10

void fun(int A[], int n) {
    int maxid = 0, max = A[0], minid = 0, min = A[0], i;
    for (i = 1; i < n; ++i) {
        if(A[i] > max) {
            max = A[i];
            maxid = i;
        }
        if(A[i] < min) {
            min = A[i];
            minid = i;
        }
    }
    i = A[0];
    A[0] = A[maxid];
    A[maxid] = i;

    i = A[n - 1];
    A[n - 1] = A[minid];
    A[minid] = i;
} // void fun(int A[], int n)


int main(){
    int A[N] = {8, 0, 1, 3, 2, 4, 9, 7, 6, 5}, i;
    fun(A, N);
    for (i = 0; i < N; ++i) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
