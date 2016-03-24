#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>

int main()

{

    printf("Parent process id:%d\n",getpid());
    pid_t iRet = fork();
    if(iRet < 0){//出错
        printf("Create child process fail!\n");
    }else if(iRet == 0){//表示子进程
        printf("child process id:%d ppid:%d\n",getpid(),getppid());
        exit(0);//进程退出
    }else{//表示父进程
        printf("parent process success,child id:%d\n",iRet);
        exit(0);//进程退出
    }
    return 0;
}

//这里if和else里面的语句都得到执行了，和我们以前的if…else结构不同，此时相当于有两份main函数代码的拷贝，其中一份做的操作是if(iRet == 0)的情况；另外一份做的操作是else(父)的情况。所以可以输出2句话。**提问：如何创建兄弟进程和爷孙进程？**
