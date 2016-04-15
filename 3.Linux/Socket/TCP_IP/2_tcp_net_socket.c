#include "2_tcp_net_socket.h"

int tcp_init(const char*ip, int port)//将socket，bind，listen都封装在一个函数里面
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in ser;
    bzero(&ser, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(port);
    ser.sin_addr.s_addr = inet_addr(ip);

    if((bind(sfd, (struct sockaddr*)&ser, sizeof(struct sockaddr))) == -1)
    {
         perror("bind");
         close(sfd);
         return -1;
    }

    if((listen(sfd, 10)) == -1)
    {
         perror("listen");
         close(sfd);
         return -1;
    }

    return sfd;
}


int tcp_accept(int sfd)//用于服务端接收
{
     struct sockaddr_in client;
     bzero(&client, sizeof(client));
     int addrlen = sizeof(struct sockaddr);
     int new_fd = accept(sfd, (struct sockaddr*)&client, &addrlen);
     if(new_fd == -1)
     {
          perror("accept");
          close(sfd);
          return -1;
     }

     printf("the ip = %s, port = %d", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
     return new_fd;
}

int tcp_connect(const char* ip, int port)//用于客户端的链接
{
     int sfd = socket(AF_INET, SOCK_STREAM, 0);
     if(-1 == sfd)
     {
         perror("socket");
         return -1;
     }

     struct sockaddr_in server;
     bzero(&server, sizeof(server));
     server.sin_family = AF_INET;
     server.sin_port = htons(port);
     server.sin_addr.s_addr = inet_addr(ip);

     if((connect(sfd, (struct sockaddr*)&server, sizeof(struct sockaddr))) == -1)
     {
          perror("connect");
          close(sfd);
          return -1;
     }
     return sfd;
}


void signalhander(void)
{
     sigset_t sigSet;
     sigemptyset(&sigSet);
     sigaddset(&sigSet, SIGINT);
     sigaddset(&sigSet, SIGQUIT);
     sigprocmask(SIG_BLOCK, &sigSet, NULL);
}
