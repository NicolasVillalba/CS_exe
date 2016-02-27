#include <stdio.h>

int fun(int n) {
    if(n / 10000 == n % 10 && n / 1000 % 10 == n / 10 % 10) return 1;
    return 0;
} // int fun(int n)


int main(){
    int n;
    scanf("%d", &n);
    printf("%s\n", fun(n) ? "YES" : "NO");
    return 0;
}
