#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>


int main()
{
    int fd = open("a.txt", O_WRONLY|O_CREAT);
    if(-1 == fd)
    {
        perror("open error");
        exit(-1);
    }
    
    printf("\n");//必不可少
    
    close(1);
    
    int fd2 = dup(fd);
    close(fd);
    
    printf("helloworld\n");
    close(fd2);
    return 0;
    
    /*该程序首先打开了一个文件，返回一个文件描述符，因为默认的就打开了0,1,2表示标准输入，标准输出，标准错误输出。而用close(1);则表示关闭标准输出，此时这个文件描述符就空着了。后面又用dup，此时dup(fd);则会复制一个文件描述符到当前未打开的最小描述符，此时这个描述符为1.后面关闭fd自身，然后在用标准输出的时候，发现标准输出重定向到你指定的文件了。那么printf所输出的内容也就直接输出到文件了。*/
}
