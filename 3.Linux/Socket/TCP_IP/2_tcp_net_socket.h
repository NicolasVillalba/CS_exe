#ifndef __TCP_NET_SOCKET_H__
#define __TCP_NET_SOCKET_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>


extern int tcp_init(const char *ip, int port);
extern int tcp_accept(int sfd);
extern int tcp_connect(const char* ip, int port);
extern void signalhander(void);


#endif
