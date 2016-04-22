 ///
 /// @file    client.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>


int main()
{
	//创建套接字
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sock)
	{
		printf("socket error\n");
		return -1;
	}

	//向服务器发起请求，特定的ip和端口
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(1234);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int ret;
	ret = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(-1 == ret)
	{
		perror("connect");
		return -1;
	}

	//读取服务器传回的数据
	char buffer[40];
	ret = read(sock, buffer, sizeof(buffer) - 1);

	printf("Message form server is : %s\n", buffer);

	//关闭套接字
	close(sock);

	return 0;
}
