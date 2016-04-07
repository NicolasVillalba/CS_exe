#一.进程间传递文件描述符

##1.writev函数

writev将多个数据存储在一起，将驻留在两个或更多的不连接的缓冲区中的数据一次写出去。



```c


#include <sys/uio.h>

ssize_t writev(int fd, const struct iovec *iov, int iovcnt);

struct iovec {
      void  *iov_base;    /* Starting address */
      size_t iov_len;     /* Number of bytes to transfer */
};
```


###实例：用writev函数将两个字符串写入文件中



+ writev.c



```c

#include "func.h"                                                                             

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("error args\n");
        return -1; 
    }   
    struct iovec iov[2];
    iov[0].iov_base = "hello";
    iov[0].iov_len = 5;
    iov[1].iov_base = "world";
    iov[1].iov_len = 5;
    int fd,ret;
    fd = open(argv[1],O_RDWR);
    if(-1 == fd){
        perror("open");
        return -1; 
    }   
    ret = writev(fd,iov,2);
    if(-1 == ret){
        perror("writev");
        return -1; 
    }   
    return 0;
}
```





##2.进程间传递文件描述符



+ 第一步：socketpair初始化类型描述符

+ 第二步：sendmsg发送文件描述符

+ 第三步：ecvmsg接收文件描述符



```c

#include <sys/types.h>          
#include <sys/socket.h>
#include <sys/uio.h>
int socketpair(int domain, int type, int protocol, int sv[2]);
ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);
struct msghdr {
      void         *msg_name;       /* optional address */
      socklen_t     msg_namelen;    /* size of address */
      struct iovec *msg_iov;        /* scatter/gather array */
      size_t        msg_iovlen;     /* # elements in msg_iov */
      void         *msg_control;    /* ancillary data, see below */
      size_t        msg_controllen; /* ancillary data buffer len */
      int           msg_flags;      /* flags on received message */
};
struct cmsghdr {

           socklen_t cmsg_len;    /* data byte count, including header */

           int       cmsg_level;  /* originating protocol */

           int       cmsg_type;   /* protocol-specific type */

           /* followed by unsigned char cmsg_data[]; */

};

struct iovec {
       void  *iov_base;    /* Starting address */
       size_t iov_len;     /* Number of bytes to transfer */
};
ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
```



###实例：进程间传递文件描述符和字符串



+ 头文件：func.h



```c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
```



+ send_fd.c



```c

#include "func.h"
void send_message(int fdw,int fd){
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov[2];
    iov[0].iov_base = "hello";
    iov[0].iov_len = 5;
    iov[1].iov_base = "world";
    iov[1].iov_len = 5;
    msg.msg_iov = iov;
    msg.msg_iovlen = 2;
    struct cmsghdr* cmsg;
    int len = CMSG_LEN(sizeof(int));
    cmsg = (struct cmsghdr*)malloc(len);
    cmsg->cmsg_len = len;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    *(int *)CMSG_DATA(cmsg) = fd;
    msg.msg_control = cmsg;
    msg.msg_controllen = len;
    int ret;
    ret = sendmsg(fdw,&msg,0);
    if(-1 == ret){
        perror("sendmsg");
        return;
    }
}

void recv_message(int fdr,int *fd){
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    char buf1[10] = {0};
    char buf2[10] = {0};
    struct iovec iov[2];
    iov[0].iov_base = buf1;
    iov[0].iov_len = 5;
    iov[1].iov_base = buf2;
    iov[1].iov_len = 5;
    msg.msg_iov = iov;
    msg.msg_iovlen = 2;
    struct cmsghdr* cmsg;
    int len = CMSG_LEN(sizeof(int));
    cmsg = (struct cmsghdr*)malloc(len);
    cmsg->cmsg_len = len;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;
    msg.msg_control = cmsg;
    msg.msg_controllen = len;
    int ret;
    ret = recvmsg(fdr,&msg,0);
    if(-1 == ret){
        perror("recvmsg");
        return;
    }
    *fd = *(int *)CMSG_DATA(cmsg);
    ret = writev(*fd,iov,2);
    if(-1 == ret){
        perror("writev");
        return;
    }
}

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("error args\n");
        return -1;
    }
    int fds[2];
    int ret;
    ret = socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
    if(-1 == ret){
        perror("socketpair");
        return -1;
    }
    if(!fork()){
        close(fds[1]);
        int fd;
        recv_message(fds[0],&fd);
        printf("child fd = %d\n",fd);
        char buf[128] = {0};
        lseek(fd,0,SEEK_SET);
        read(fd,buf,sizeof(buf));
        printf("%s\n",buf);
        exit(0);
    }else{
        close(fds[0]);
        int fd;
        fd = open(argv[1],O_RDWR);
        if(-1 == fd){
            perror("open");
            return -1;
        }
        printf("parent fd = %d\n",fd);
        send_message(fds[1],fd);
        wait(NULL);
        return 0;
    }   
    return 0;
}
```




