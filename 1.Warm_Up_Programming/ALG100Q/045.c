#include <stdio.h>

int main(){
    register int i;
    int sum = 0;
    for (i = 1; i <= 100; ++i) {
        sum += i;
    }
    printf("Sum:%d\n", sum);
    return 0;
}
