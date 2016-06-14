 ///
 /// @file    04_wait.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using std::cout;
using std::endl;
int main()
{
	pid_t pid = fork();
	if(pid == 0)
		exit(10);
	else
	{
		wait(NULL);//NULL表示等待所有进程
		sleep(10);//将sleep放在wait后面，否则会出现僵尸进程
	}
}
