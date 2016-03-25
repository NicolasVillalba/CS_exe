//无名管道

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
    int fds[2];
    pipe(fds);//打开管道
    if(!fork())//子进程
    {
        close(fds[0]);//先关闭读端
        write(fds[1], "hello", 5);
        close(fds[1]);//写完之后关闭写端
        exit(0);
    }else{//父进程
        close(fds[1]);//先关闭写端
        char buf[10] = {0};
        read(fds[0], buf, sizeof(buf));
        printf("i am a parent. the buf is %s\n", buf);
        close(fds[0]);//读完之后关闭读端
        return 0;
    }
}

//benchmark最大的读写的百M
