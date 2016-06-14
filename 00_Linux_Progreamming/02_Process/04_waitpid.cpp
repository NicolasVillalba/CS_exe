 ///
 /// @file    04_waitpid.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
void SignChildPsExit(int iSignNo)
{
    int iExitCode;
    pid_t pid = waitpid(-1,NULL,0); 
        //表示等待任何进程，并阻塞。如果换成waitpid(-1,NULL,WNOHANG);则跟没有写waitpid效果类似，此时父进程没有阻塞
    printf("SignNo:%d   child %d exit\n",iSignNo,pid);
    if(WIFEXITED(iExitCode))
            {
        printf("Child exited with code %d\n", WEXITSTATUS(iExitCode));
            }
    sleep(10);
}
int main()
{
    signal(SIGCHLD, SignChildPsExit);//利用信号函数
    printf("Parent process id:%d\n", getpid());
    pid_t iRet = fork();
    if(iRet == 0)
        exit(3);
    return 0;
}
