#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args\n");
        return -1;
    }
    
    int ret;
    ret = open("file.txt", O_RDONLY | O_CREAT, 0666);//打开，如果有文件则只读，否则创建
    if(-1 == ret)
    {
        perror("open filed\n");
        return -1;
    }
    printf("ret is %d\n", ret);
    close(ret);
    return 0;
}
