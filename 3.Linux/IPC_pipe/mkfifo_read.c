#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    char buf[128] = {0};
    int fd = open("Myfifo.pip", O_RDONLY);
    if(read(fd, buf, sizeof(buf)) > 0)
        puts(buf);
    close(fd);
    return 0;
}
