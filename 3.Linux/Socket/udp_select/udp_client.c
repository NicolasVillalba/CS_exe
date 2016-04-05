#include "func.h"

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("error args\n");
        return -1;
    }
    
    int sfd;
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(-1 == sfd)
    {
        perror("socket");
        return -1;
    }
    
    struct sockaddr_in ser;
    bzero(&ser, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(atoi(argv[2]));
    ser.sin_addr.s_addr = inet_addr(argv[1]);
    
    int ret;
    fd_set rdset;
    char buf[128] = {0};
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(0, &rdset);
        FD_SET(sfd, &rdset);
        ret = select(sfd + 1, &rdset, NULL, NULL, NULL);
        if(ret > 0)
        {
            if(FD_ISSET(sfd, &rdset))
            {
                bzero(buf, sizeof(buf));
                ret = recvfrom(sfd, buf, sizeof(buf), 0, NULL, NULL);
                if(ret == -1)
                {
                    perror("recvfrom");
                    return -1;
                }
                printf("%s\n", buf);
            }
            if(FD_ISSET(0, &rdset))
            {
                bzero(buf, sizeof(buf));
                read(0, buf, sizeof(buf));
                ret = sendto(sfd, buf, strlen(buf) - 1, 0, (struct sockaddr*)&ser, sizeof(struct sockaddr));
                if(-1 == ret)
                {
                    perror("sendto");
                    return -1;
                }
            }
        }
    }
    close(sfd);
}
