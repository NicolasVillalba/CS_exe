#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>


int main()
{
    int fd = open("Myfifo.pip", O_WRONLY);
    write(fd, "hello", 6);
    close(fd);
    return 0;
}
