#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    printf("pid : %d,   ppid : %d\n", pid, ppid);
    return 0;
}
