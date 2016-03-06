#include<stdio.h>
#include<setjmp.h>

jmp_buf envbuf;//线程


void func()
{
    printf("I am func.\n");
    longjmp(envbuf, 5);
}


int main()
{
    int ret;
    ret = retjmp(envbuf);
    if(ret == 0) func();
    return 0;
}

