#include <stdio.h>

double fun() {
    double ret = 0;
    int i, deno = 0;
    for(i = 1; i <= 50; ++i) {
        deno += i;
        ret += 1.0 / deno;
    }
    return ret;
}

int main(){
    printf("%f\n", fun());
    return 0;
}
