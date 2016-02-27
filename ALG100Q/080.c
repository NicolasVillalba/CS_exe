#include <stdio.h>
#define N 1000

int check(int *n) {
    if(*n % 5 != 1) return 0;
    *n /= 5;
    return 1;
}

int fun(int n) {
    if(check(&n))
        if(check(&n))
            if(check(&n))
                if(check(&n))
                    if(check(&n))
                        return 1;
    return 0;
} // void fun(int n)

int main(){
    int i;
    for (i = 1; i < N; ++i) {
        if(fun(i)) printf("%d\n", i);
    }
    return 0;
}
