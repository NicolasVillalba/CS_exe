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
    fd = popen(argv[1], "r");
    if(NULL == fd)
    {
        perror("popen");
        return -1;
    }
    char buf[128] = {0};
    int ret;
    ret = fread(buf, sizeof(char), sizeof(buf), fd);
    if(ret < 0)
    {
        perror("fread\n");
        return -1;
    }
    printf("%s\n", buf);
    return 0;
}
