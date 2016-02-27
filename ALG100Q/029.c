#include <stdio.h>

int fun(int n) {
    if(n == 0) return 0;
    printf("%d", n % 10);
    int t = fun(n / 10);
    return 1 + t;
} // void fun(int n)


int main(){
    int n, cnt;
    scanf("%d", &n);
    cnt = fun(n);
    printf("\nDigits:%d\n", cnt);
    return 0;
}
