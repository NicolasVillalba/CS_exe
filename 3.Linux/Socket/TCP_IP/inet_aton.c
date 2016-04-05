// ./a.out  192.168.1.155
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        printf("error args\n");
        return -1;
    }
    struct in_addr addr;
    int ret;
    ret = inet_aton(argv[1], &addr);
    if(ret == 0)
    {
        perror("inet_aton");
        return -1;      
    }
    printf("addr = %x\n", addr.s_addr);//转换成二进制
    
    
    
    //解析端口号
    printf("%s\n", inet_ntoa(addr));//二进制转十进制
    printf("in_addr_t = %x\n", inet_addr(argv[1]));//转换成二进制
    return 0;
}
