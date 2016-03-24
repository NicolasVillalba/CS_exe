#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        while(1);//子进程继续
    }else{
        exit(1);//退出父进程
    }
}
