#include <stdio.h>

void fun() {
    static int callCnt = 0;
    ++callCnt;
    printf("This function has been called %d time%s.\n",
           callCnt, callCnt == 1 ? "" : "s");
} // void fun()


int main(){
    int i;
    for (i = 0; i < 10; ++i)
        fun();
    return 0;
}
