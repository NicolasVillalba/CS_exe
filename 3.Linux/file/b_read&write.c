#include<unistd.h>//read,write所需要包含的头文件

#include<stdio.h>
#include<stdlib.h>//exit包含的头文件
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>//perror

#define FILENAEM1 "aaa.txt"
#define FILENAEM2 "bbb.txt"


//本程序实现的功能是创建一个文件，然后从一个文件读取信息之后写入创建文件中
int main(int argc, char* argv[])
{
    char buf[512] = {0};
    int fo1 = open(FILENAEM1, O_RDONLY | O_CREAT);//打开文件
    int fo2 = creat(FILENAEM2, 0755);//创建文件
    if((-1 == fo1) || (-1 == fo2))
    {
        perror("open failed\n");
        exit(-1);
    }
    
    
    int fr = 0;
    while((fr = read(fo1, buf, sizeof(buf))) > 0)
    //如果read读取成功，返回的是长度，否则返回-1
    {
        int fw = write(fo2, buf, fr);
        if(-1 == fw)
        {
            perror("write failed\n");
            exit(-1);
        }
    }
    close(fo1);
    close(fo2);//文件不使用之后需要关闭
    return 0;
}

