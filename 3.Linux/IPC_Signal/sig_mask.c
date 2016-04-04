#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void handle(int sig, siginfo_t *p, void *p1)
{
    printf("before the sleep, the sig is %d\n", sig);
    sleep(5);
    sigset_t s1;
    sigpending(&s1);
    if(sigismember(&s1, SIGQUIT))
    {
        printf("the sigquit is here\n");
    }
    printf("after the sleep, the sig is %d\n", sig);
}



int main()
{
    int ret;
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = handle;
    act.sa_flags = SA_SIGINFO;//首先响应
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    ret = sigaction(SIGINT, &act, NULL);
    if(ret != 0)
    {
        perror("sigaction");
        return -1;
    }
    ret = sigaction(SIGQUIT,&act, NULL);
    if(ret != 0)
    {
        perror("sigaction");
        return -1;
    }
    while(1);
    return 0;
    
}
