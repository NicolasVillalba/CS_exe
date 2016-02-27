#include <stdio.h>
#define N 12
void fun() {
    int Tri[N][N] = { 0 }, i, j;

    for (i = 1; i < N; ++i) {
        Tri[i][1] = Tri[i][i] = 1;
    }

    for (i = 1; i < N - 1; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("%3d ", Tri[i][j]);
            Tri[i+1][j+1] = Tri[i][j] + Tri[i][j+1];
        }
        printf("\n");
    }
} // void fun(int line)


int main(){
    fun();
    return 0;
}
