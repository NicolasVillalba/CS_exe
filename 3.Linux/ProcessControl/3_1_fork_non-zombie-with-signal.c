#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

void SignChildPsExit(int iSignNo)
{
    int iExitCode;
    pid_t pid = wait(&iExitCode);//等待子进程的退出，没有这句话会出现僵尸进程
    printf("SignNo: %d  Child %d exit \n", iSignNo, pid);
    if(WIFEXITED(iExitCode))
    {
        printf("Child exited with code %d\n", WEXITSTATUS(iExitCode));
    }
    sleep(10);
}

int main()
{
    signal(SIGCHLD, SignChildPsExit);
    printf("Parent process id %d\n", getpid());
    pid_t iRet = fork();
    if(iRet == 0)
        exit(3);
}
