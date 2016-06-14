 ///
 /// @file    04_Orphaned.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using std::cout;
using std::endl;

int main()
{
	pid_t pid = fork();
	if(pid == 0)
		while(1);//保持子进程一直在运行
	else
		exit(10);//退出父进程
	return 0;
}
//可以ps -ef查看子进程在运行，父进程是1号进程
