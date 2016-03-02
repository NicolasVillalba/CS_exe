#include <stdio.h>
#define swap(a, b) {\
        int t = a; \
        a = b; \
        b = t; \
    }
int main(){
    int a = 10, b = 20;
    swap(a, b);
    printf("%d %d\n", a, b);
    return 0;
}
