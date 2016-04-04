#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

void handle(int sig)
{
    printf("the sig is %d\n", sig);
}



int main()
{
    if(signal(SIGINT, SIG_IGN) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    sleep(10);
    signal(SIGINT, SIG_DFL);
    while(1);
    return 0;
}
