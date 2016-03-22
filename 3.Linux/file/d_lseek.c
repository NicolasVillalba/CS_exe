#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<time.h>
#include<stdlib.h>


int main()
{
    int fd = open("aaa.txt", O_RDONLY);
    if(-1 == fd)
    {
        perror("open error");
        exit(-1);
    }
    
    struct stat buf;
    int ret = fstat(fd, &buf);
    if(-1 == ret)
    {
        perror("fstat error");
        exit(-1);
    }
    
    if(S_ISREG(buf.st_mode))
    {
        printf("regular file!\n");
    }
    
    if(S_ISDIR(buf.st_mode))
    {
        printf("directory!\n");
    }
    
    if(S_ISLNK(buf.st_mode))
        printf("link file！\n");
        
    printf("the size of the file is : %d\n", buf.st_size);
    
    time_t tt = buf.st_atime;
    struct tm *pt = gmtime(&tt);
    printf("%4d-%02d-%02d    %02d:%02d:%02d\n", (1900+pt->tm_year), (1+pt->tm_mon), pt->tm_mday, (8+pt->tm_hour), pt->tm_min, pt->tm_sec);
    close(fd);
    return 0;
}
