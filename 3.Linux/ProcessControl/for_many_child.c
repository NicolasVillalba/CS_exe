#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
    int i;
    pid_t pid;
    for(i = 0; i < 10; i++)
    {
        pid = fork();
        if(pid == 0)
        {
            printf("mypid is %d\n", getpid());
            while(1);
            exit(0);
        }
    }
    printf("I have create 10 child \n");
    while(1);
    return 0;
}
