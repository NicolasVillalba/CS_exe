 ///
 /// @file    server.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
using std::cout;
using std::endl;

int main()
{
	int listenfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == listenfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8888);//从小端模式到大端模式转换，即从主机序到网络字节序
	serveraddr.sin_addr.s_addr = inet_addr("192.168.1.77");//将点分十进制转换成

	if(-1 == ::bind(listenfd, 
				(struct sockaddr*)&serveraddr, 
				sizeof(struct sockaddr)))
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if( -1 == ::listen(listenfd, 10));
	{
		perror("listen");
		close(listenfd);
		exit(EXIT_FAILURE);
	}

	int peerfd = ::accept(listenfd, NULL, NULL);
	if( -1 == peerfd);
	{
		perror("accept");
		close(listenfd);
		exit(EXIT_FAILURE);
	}

	char buff[1024] = "Welcome to server";
//	memset(buff, 0, sizeof(buff));	
	int ret = ::write(peerfd, buff, 1024);

	while(1)
	{
		int ret = ::recv(peerfd, buff, 1024, 0);//接收
		printf("%s\n", buff);


		ret = ::send(peerfd, buff,strlen(buff), 0);//发送
	}

	return 0;
}
