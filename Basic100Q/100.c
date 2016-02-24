#include <stdio.h>

double fun(int n) {
    double ret = 1, last = 1;
    int i;
    if(n == 1) return ret;
    for(i = 2; i <= n; ++i) {
        last += i * 0.5;
        ret += last;

    }
    return ret;
}

int main(){
    printf("%.1f\n", fun(100));
    return 0;
}
