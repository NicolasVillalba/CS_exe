#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

//获得文件大小
int main()
{
    struct stat buf;
    stat("/etc/passwd",  &buf);
    printf("/etc/passwd file size = %d\n", buf.st_size);
    return 0;
}
