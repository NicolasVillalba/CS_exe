#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        exit(10);
    }else{
        wait(NULL);//表示等待所有进程
        sleep(10);
    }
}
