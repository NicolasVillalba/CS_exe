#include<sys/mman.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/fcntl.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args\n");
        return -1;
    }
    int fd;
    fd = open(argv[1], O_RDWR);
    if(-1 == fd)
    {
        printf("open filed!\n");
        return -1;
    }
    char *p;
    p  =  mmap(NULL, 1<<10,PROT_READ|PROT_WRITE,MAP_SHARED, fd ,0);
    if(p == (char*)-1)
    {
        perror("nmap");
        return -1;
    }
    
    printf("p[0] is %c\n", p[0]);
    munmap(p, 1<<10);
    return 0;
}
