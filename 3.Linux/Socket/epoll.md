##1、基本知识

> epoll是在2.6内核中提出的，是之前的select和poll的增强版本。相对于select和poll来说，epoll更加灵活，没有描述符限制。epoll使用一个文件描述符管理多个描述符，将用户关系的文件描述符的事件存放到内核的一个事件表中，这样在用户空间和内核空间的copy只需一次。

##2、epoll接口

+ epoll操作过程需要三个接口，分别如下：

```c
#include <sys/epoll.h>
int epoll_create(int size);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
```
####（1） int epoll_create(int size);

> 创建一个epoll的句柄，size用来告诉内核这个监听的数目一共有多大。这个参数不同于select()中的第一个参数，给出最大监听的fd+1的值。需要注意的是，当创建好epoll句柄后，它就是会占用一个fd值，在linux下如果查看/proc/进程id/fd/，是能够看到这个fd的，所以在使用完epoll后，必须调用close()关闭，否则可能导致fd被耗尽。

####（2）int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

> epoll的事件注册函数，它不同与select()是在监听事件时告诉内核要监听什么类型的事件epoll的事件注册函数，它不同与select()是在监听事件时告诉内核要监听什么类型的事件，而是在这里先注册要监听的事件类型。第一个参数是epoll_create()的返回值，第二个参数表示动作，用三个宏来表示：

+ EPOLL_CTL_ADD：注册新的fd到epfd中；
+ EPOLL_CTL_MOD：修改已经注册的fd的监听事件；
+ EPOLL_CTL_DEL：从epfd中删除一个fd；

+ 第三个参数是需要监听的fd，第四个参数是告诉内核需要监听什么事，struct epoll_event结构如下：
```c
struct epoll_event {
  __uint32_t events;  /* Epoll events */
  epoll_data_t data;  /* User data variable */
};
```

+ events可以是以下几个宏的集合：

1.EPOLLIN ：表示对应的文件描述符可以读（包括对端SOCKET正常关闭）；
2.EPOLLOUT：表示对应的文件描述符可以写；
3.EPOLLPRI：表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）；
4.EPOLLERR：表示对应的文件描述符发生错误；
5.EPOLLHUP：表示对应的文件描述符被挂断；
5.EPOLLET： 将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的。
6.EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里

####（3） int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);

> 等待事件的产生，类似于select()调用。参数events用来从内核得到事件的集合，maxevents告之内核这个events有多大，这个maxevents的值不能大于创建epoll_create()时的size，参数timeout是超时时间（毫秒，0会立即返回，-1将不确定，也有说法说是永久阻塞）。该函数返回需要处理的事件数目，如返回0表示已超时。

##3、工作模式

> epoll对文件描述符的操作有两种模式：LT（level trigger）和ET（edge trigger）。LT模式是默认模式，LT模式与ET模式的区别如下：

+ LT模式：当epoll_wait检测到描述符事件发生并将此事件通知应用程序，应用程序可以不立即处理该事件。下次调用epoll_wait时，会再次响应应用程序并通知此事件。

+ ET模式：当epoll_wait检测到描述符事件发生并将此事件通知应用程序，应用程序必须立即处理该事件。如果不处理，下次调用epoll_wait时，不会再次响应应用程序并通知此事件。

> ET模式在很大程度上减少了epoll事件被重复触发的次数，因此效率要比LT模式高。epoll工作在ET模式的时候，必须使用非阻塞套接口，以避免由于一个文件句柄的阻塞读/阻塞写操作把处理多个文件描述符的任务饿死。


##4.测试程序

```c
//tcp_server.c
#include "func.h"

void set_nonblock(int* sfd)
{
	int status;
	status=fcntl(*sfd,F_GETFL);
	status=status|O_NONBLOCK;
	fcntl(*sfd,F_SETFL,status);	
}
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));//端口转换为网络字节序
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	ret=listen(sfd,LNUM);
	if(-1==ret)
	{
		perror("listen");
		return -1;
	}
	struct sockaddr_in client;
	int len=sizeof(struct sockaddr);
	int new_fd=-1;
	char buf[10]={0};
	int epfd=epoll_create(1);
	if(-1==epfd)
	{
		perror("epfd");
		return -1;
	}
	struct epoll_event event,evs[3];
	event.events=EPOLLIN;
	event.data.fd=0;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,0,&event);
	if(-1==ret)
	{
		perror("epoll_ctl");
		return -1;
	}
	event.events=EPOLLIN;
	event.data.fd=sfd;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
	if(-1==ret)
	{
		perror("epoll_ctl1");
		return -1;
	}
	int i;
	while(1)
	{
		bzero(evs,sizeof(evs));
		ret=epoll_wait(epfd,evs,3,-1);
		for(i=0;i<ret;i++)
		{
			if(evs[i].events == EPOLLIN && evs[i].data.fd == sfd)
			{	
				new_fd=accept(sfd,(struct sockaddr*)&client,&len);	
				if(-1==new_fd)
				{
					perror("accept");
					return -1;
				}
				printf("client ip=%s,port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
				event.events=EPOLLIN|EPOLLET;
				event.data.fd=new_fd;
				set_nonblock(&new_fd);
				epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&event);
			}
			if(evs[i].events == EPOLLIN && evs[i].data.fd == new_fd)
			{
				while(1)
				{
					bzero(buf,sizeof(buf));
					ret=recv(new_fd,buf,sizeof(buf),0);
					if(ret >0)
					{
						printf("%s\n",buf);
					}else if(ret == -1)
					{
						break;	
					}else if(ret==0){
						close(new_fd);
						//event.events=EPOLLIN;
						event.data.fd=new_fd;
						epoll_ctl(epfd,EPOLL_CTL_DEL,new_fd,&event);
					}
				}
			}
			if(evs[i].events == EPOLLIN && evs[i].data.fd == 0)
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));
				ret=send(new_fd,buf,strlen(buf)-1,0);
				if(ret<0)
				{
					perror("send");
					return -1;
				}
			}
		}
	}
	close(sfd);
}
```

```c
//tcp_client.c
#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));//端口转换为网络字节序
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	fd_set rdset;
	char buf[128]={0};
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(sfd,&rdset);
		ret=select(sfd+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(0,&rdset))
			{
				bzero(buf,sizeof(buf));
				read(0,buf,sizeof(buf));	
				ret=send(sfd,buf,strlen(buf)-1,0);
				if(-1==ret)
				{
					perror("send");
					return -1;
				}
			}
			if(FD_ISSET(sfd,&rdset))
			{
				bzero(buf,sizeof(buf));
				ret=recv(sfd,buf,sizeof(buf),0);
				if(-1==ret)
				{
					perror("recv");
					return -1;
				}
				printf("%s\n",buf);
			}
		}
	}
			close(sfd);
}
			
```

```c
//func.h
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/epoll.h>
#include <sys/select.h>
#include <fcntl.h>
#define LNUM 10
```
