//守护进程
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>


int main()
{
    if(fork())//父进程
    {
        exit(0);
    }
    setsid();//子进程
    chdir("/");
    umask(0);
    int i;
    
    for(i = 0; i < 3; i++)
        close(i);//关闭进程描述符
        
    while(1){//守护进程
        sleep(1);
    }
    return 0;
}
