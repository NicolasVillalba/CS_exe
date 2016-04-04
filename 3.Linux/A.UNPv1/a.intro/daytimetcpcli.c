#include "../unp.h"

int main(int argc, char** argv[])
{
     int sockfd, n;
     char recvline[MAXLINE + 1];
     
     struct sockaddr_in servaddr;
     
     if(argc != 2)
        err_quit("usage: a.out<IPaddress>");
     
     
}
