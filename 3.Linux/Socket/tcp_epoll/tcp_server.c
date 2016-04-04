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
