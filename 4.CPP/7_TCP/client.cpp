 ///
 /// @file    client.cpp
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
	int clientfd = ::socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == clientfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(8888);
	serveraddr.sin_addr.s_addr = inet_addr("192.168.1.77");

	if( -1 == connect(clientfd, (const  sockaddr *)&serveraddr, socklen_t(sizeof(struct sockaddr))))
	{
		perror("connect");
		close(clientfd);
		exit(EXIT_FAILURE);
	}


	char buff[1024];
	memset(buff, 0, sizeof(buff));
	int ret = ::read(clientfd, buff, sizeof(buff));
	printf("%s\n", buff);

	while(1)
	{
		fgets(buff, sizeof(buff), stdin);
		ret = ::write(clientfd, buff, strlen(buff));

		memset(buff, 0, sizeof(buff));
		ret = ::read(clientfd, buff, sizeof(buff));

		printf("%s\n", buff);
	}
	return 0;
}
