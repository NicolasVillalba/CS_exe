#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void handle(int sig)
{
    printf("before sleep, the sig is %d\n", sig);
    sleep(5);
    printf("after sleep, the sig is %d\n", sig);
}


//每个信号最多执行2次
int main()
{
    if(signal(SIGINT, handle) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    char buf[128] = {0};
    read(0, buf, sizeof(buf));
    return 0;
}
