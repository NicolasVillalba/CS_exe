#include <stdio.h>

void fun(int n) {
    int i;
    double res = 0;
    for (i = 1; i <= n; ++i) {
        res += (1.0 / (2 * i - 1) - 1.0 / (2 * i));
    }
    printf("%lf\n", res);
}

int main(){
    fun(2);
    return 0;
}
