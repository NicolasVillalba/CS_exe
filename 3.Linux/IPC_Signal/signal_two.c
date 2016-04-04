#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

void handle(int sig)
{
    printf("before sleep, the sig is %d\n", sig);
    sleep(5);
    printf("after sleep, the sig is %d\n", sig);
}



int main()
{
    if(signal(SIGINT, handle) == SIG_ERR)
    {
        perror("signal");
        return -1;
    }
    signal(SIGQUIT, handle);
    while(1);
    return 0;
}
