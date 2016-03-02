#include <stdio.h>
#include "044.extern.h"

int main(){
    extern int A;
    printf("%d\n", A);
    fun();
    ++A;
    fun();
    return 0;
}
