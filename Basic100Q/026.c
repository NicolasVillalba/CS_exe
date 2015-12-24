//参考大神代码
#include <stdio.h>

long double fun(double p) {
    long double ret = 0, multiplier = 1, multiplicant = 1;
    int i;
    for(i = 1; multiplier / multiplicant >= 0.0005; ++i) {
        printf("%Lf / %Lf\n", multiplier, multiplicant);
        ret += multiplier / multiplicant;
        multiplier *= i;
        multiplicant *= 2 * i + 1;
    }
    return ret * 2;
}

int main(){
    printf("%.32Lf\n", fun(0.0005));
    return 0;
}
