 ///
 /// @file    3_fork1.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
using std::cout;
using std::endl;

int main()
{
	printf("Parent process id :%d\n", getpid());
	pid_t pc = fork();
	if(pc < 0)
		printf("create child process failed!\n");
	else if(pc == 0)//子进程
		printf("child process id:%d	ppid:%d\n", getpid(), getppid());
	else//父进程
		printf("parent process success, child id: %d\n", pc);
	return 0;
}
