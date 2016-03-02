#include <stdio.h>

double fun_odd(int n) {
    int i;
    double ret = 0;
    for (i = 1; i <= n; i += 2) {
        ret += 1.0 / i;
    }
} // double fun_odd(int n)

double fun_even(int n) {
    int i;
    double ret = 0;
    for (i = 2; i <= n; i += 2) {
        ret += 1.0 / i;
    }
} // double fun_even(int n)

double fun_call(int n) {
    if(n % 2) return fun_odd(n);
    return fun_odd(n);
} // void fun_call(int n)


int main(){
    printf("%lf\n", fun_call(10));
    printf("%lf\n", fun_call(11));
    return 0;
}
