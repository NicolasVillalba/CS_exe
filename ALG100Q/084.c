#include <stdio.h>

int isPrime(int n) {
    int i;
    if(n == 2) return 1;
    for (i = 2; i * i <= n; ++i) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void fun(int n) {
    int i;
    for (i = 2; i < n; ++i) {
        if(isPrime(i) && isPrime(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
        }
    }
} // void fun(int n)

int main(){
    int n;
    scanf("%d", &n);
    fun(n);
    return 0;
}
