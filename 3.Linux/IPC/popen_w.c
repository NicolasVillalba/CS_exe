#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args\n");
        return -1;
    }
    
    FILE *fd;
    fd = popen(argv[1], "w");
    if(NULL == fd)
    {
        perror("popen");
        return -1;
    }
    char buf[128] = "3 4";
    int ret;
    ret = fwrite(buf, sizeof(char), strlen(buf), fd);
    if(ret < 0)
    {
        perror("frite");
        return -1;
    }
    pclose(fd);
    return 0;
}
