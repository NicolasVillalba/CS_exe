#include<sys/uio.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>



int main(int argc, char* argv[])
{
     if(argc != 2)
     {
         printf("error args\n");
         return -1;
     }

     struct iovec iov[2];
     iov[0].iov_base = "hello";
     iov[0].iov_len = 5;
     iov[1].iov_base = "world";
     iov[1].iov_len = 5;
     int fd, ret;
     fd = open(argv[1], O_RDWR);
     if(-1 == fd)
     {
          perror("open");
          return -1;
     }

     ret = writev(fd, iov, 2);
     if(-1 == ret)
     {
          perror("writev");
          return -1;
     }
     return 0;
}
