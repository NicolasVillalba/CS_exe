//改变文件大小
//原型
//#include <unistd.h>
//int ftruncate(int fd, off_t length);
//参数fd为已打开的文件描述词，而且必须是以写入模式打开的文件。如果原来的文件大小比参数length大，则超过的部分会被删去。

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int fd = open("aaa.txt", O_WRONLY);
    ftruncate(fd, 10);//10是一个界限，要是文件比10大，增多出来的删除
    close(fd);
    return 0;
}
