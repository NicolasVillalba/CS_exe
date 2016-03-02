#include <stdio.h>

double fun(int n) {
    int i;
    double ret = 0;
    for(i = 5; i <= n; ++i) {
        if(i % 5 == 0 || i % 9 == 0) {
            ret += 1.0 / i;
        }
    }
    return ret;
}

int main(){
    printf("%f\n", fun(100));
    return 0;
}
