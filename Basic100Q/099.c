#include <stdio.h>
#include <math.h>

double fun(int n) {
    int i, j, flag;
    double ret = 0;
    for(i = 3; i <= n; ++i) {
        flag = 1;
        for(j = 2; j *j <= i; ++j) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) ret += sqrt(i);
    }
    return ret;
}

int main(){
    printf("%f\n", fun(100));
    return 0;
}
