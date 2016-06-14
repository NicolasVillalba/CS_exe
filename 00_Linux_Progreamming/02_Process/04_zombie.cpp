 ///
 /// @file    04_zombie.cpp
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
		exit(10);//退出子进程
	else
		sleep(10);//父进程睡10秒
	return 0;
}
//用ps -elf查看为z的僵尸进程
