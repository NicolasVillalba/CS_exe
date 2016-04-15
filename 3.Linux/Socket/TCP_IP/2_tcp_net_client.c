#include "2_tcp_net_socket.h"


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("error args\n");
        return -1;
    }

    int sfd = tcp_connect(argv[1], atoi(argv[2]));
    char buf[512] = {0};
    if((send(sfd, "hello", 6, 0)) == -1)
    {
         perror("send");
         close(sfd);
         return -1;
    }

    if((recv(sfd, buf, sizeof(buf), 0)) == -1)
    {
         perror("recv");
         close(sfd);
         return -1;
    }
    printf("%s\n", buf);
    close(sfd);
    return 0;
}
