#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
    act.sa_flags = SA_SIGINFO;
    ret = sigaction(SIGINT, &act, NULL);
    if(ret != 0)
    {
        perror("sigaction");
        return -1;
    }
    while(1);
    return 0;
    
}
