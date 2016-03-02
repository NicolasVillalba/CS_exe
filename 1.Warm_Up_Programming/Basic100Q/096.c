#include <stdio.h>
#include <math.h>
#define N 9

double fun(int A[]) {
    double ret = 0;
    int i;
    for(i = 1; i < N; ++i) {
        ret += sqrt((A[i - 1] + A[i]) / 2.0);
    }
    return ret;
}

int main(){
    int A[N] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    printf("%f\n", fun(A));
    return 0;
}
