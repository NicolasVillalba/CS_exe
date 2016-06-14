 ///
 /// @file    07_deamon1.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
using std::cout;
using std::endl;

void Deamon()
{
	const int Maxfd = 64;
	int i = 0;
	if(fork() > 0)
		exit(0);//退出父进程
	setsid();//让进程摆脱原会话的控制，让该进程摆脱原进程组的控制，让进程摆脱原控制终端的控制；
	chdir("/");//设置工作目录为根目录，linux默认当前工作目录不允许卸载
	umask(0);//重置文件访问权限掩码为0，这样在对文件操作过程中不会有权限问题
	for(;i < Maxfd; i++)//尽可能关闭所有从父进程那里继承来的文件
		close(i);
}

int main()
{
	Deamon();//成为守护进程
	while(1)
		sleep(1);
	return 0;
}
//运行结果用ps -elf查看
//当运行多次即创建多个守护进程的时候，每个pid相差2
//通过kill pid杀死进程
