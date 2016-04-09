#include "func.h"

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("error args\n");
        return -1;
    }
    int sfd;
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in ser;
    bzero(&ser, sizeof(ser));
    ser.sin_family = AF_INET;//ipv4
    ser.sin_port = htons(atoi(argv[2]));//Port
    ser.sin_addr.s_addr = inet_addr(argv[1]);//IP

    int ret;//绑定
    ret = bind(sfd, (struct sockaddr *)&ser, sizeof(struct sockaddr));
    if(-1 == ret)
    {
         perror("bind");
         close(sfd);
         return -1;
    }

    ret = listen(sfd, LNUM);
    if(-1 == ret)
    {
         perror("listen");
         close(sfd);
         return -1;
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(struct sockaddr));
    int len = sizeof(struct sockaddr);
    int new_fd = accept(sfd, (struct sockaddr*)&client, &len);
    if(-1 == new_fd)
    {
         perror("accept");
         close(sfd);
         return -1;
    }
    printf("client ip = %s , port = %d success connect\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));



    char buf[512] = {0};
    ret = recv(new_fd, buf, sizeof(buf), 0);
    if(ret < 0)
    {
         perror("recv");
         close(sfd);
         return -1;
    }
    printf("the buf is %s", buf);

    ret = send(new_fd, "hello", 6, 0);
    if(0 > ret)
    {
         perror("send");
         close(sfd);
         return -1;
    }

    close(new_fd);
    close(sfd);
    return 0;
}
