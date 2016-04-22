 ///
 /// @file    server.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
	//创建套接字
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(-1 == serv_sock)
	{
		printf("serv_sock error\n");
		return -1;
	}

	//绑定套接字IP和端口
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));//初始化为0
	serv_addr.sin_family = AF_INET;//使用ipv4协议
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//ip
	serv_addr.sin_port = htons(1234);//端口
	int ret;
	ret = bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));//绑定
	if(-1 == ret)
	{
		perror("bind");
		return -1;
	}

	//监听
	ret = listen(serv_sock, 20);
	if(-1 == ret)
	{
		perror("listen");
		return -1;
	}

	//接收客户端请求
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if(-1 == clnt_sock)
	{
		perror("accept");
		return -1;
	}


	//向客户端发送数据
	char str[] = "Hello World!";
	ret = write(clnt_sock, str, sizeof(str));
	if(-1 == ret)
	{
		perror("write");
		return -1;
	}
	
	close(serv_sock);
	return 0;
}
