#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args");
        return -1;
    }
    int ret;
    ret = mkfifo(argv[1], 0666);
    if(ret == -1)
    {
        perror("mkfio failed");
        return -1;
    }
    return 0;
}
