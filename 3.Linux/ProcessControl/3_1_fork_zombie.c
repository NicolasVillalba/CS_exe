#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
    pid_t pid = fork();//创建一个子进程
    if(pid == 0)
    {
        exit(10);
    }else{
        sleep(10);
    }
}
