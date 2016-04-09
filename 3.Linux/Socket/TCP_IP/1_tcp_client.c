#include "func.h"


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("error args\n");
        return -1;
    }

    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sfd)
    {
         perror("socket");
         return -1;
    }

    struct sockaddr_in client;
    memset(&client, 0, sizeof(struct sockaddr));
    client.sin_family = AF_INET;
    client.sin_port = htons(atoi(argv[2]));
    client.sin_addr.s_addr = inet_addr(argv[1]);
    int ret;
    ret = connect(sfd, (struct sockaddr*)&client, sizeof(struct sockaddr));
    if(-1 == ret)
    {
         perror("connect");
         close(sfd);
         return -1;
    }

    ret = send(sfd, "hello", 6, 0);
    if(-1 == ret)
    {
         perror("send");
         close(sfd);
         return -1;
    }

    char buf[512] = {0};
    ret = recv(sfd, buf, sizeof(buf), 0);
    if(-1 == ret)
    {
         perror("recv");
         close(sfd);
         return -1;
    }
    printf("I am client, the buf is %s", buf);

    close(sfd);
    return 0;
}
