#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


void handle(int sig, siginfo_t *p, void *p1)
{
    printf("the sig is %d\n", sig);
}



int main()
{
    int ret;
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = handle;
    act.sa_flags = SA_SIGINFO|SA_RESTART;//
    ret = sigaction(SIGINT, &act, NULL);
    if(ret != 0)
    {
        perror("sigaction");
        return -1;
    }
    char buf[128] = {0};
    int rets;
    rets = read(0, buf, sizeof(buf));//前面处理信号以后后面出差
    if(rets == -1)
    {
        perror("read");
        return -1;
    }
    return 0;
    
}
