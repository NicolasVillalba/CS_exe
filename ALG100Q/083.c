#include <stdio.h>

/* 0,1,2,3,4,5,6,7 */

void fun() {
    long sum = 4, s = 4;
    int i;
    for (i = 2; i <= 8; ++i) {
        if(i == 2) s *= 7;
        else s *= 8;
        sum += s;
    }
    printf("%ld\n", sum);
} // void fun()

int main(){
    fun();
    return 0;
}
