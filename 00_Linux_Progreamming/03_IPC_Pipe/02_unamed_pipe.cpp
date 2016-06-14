 ///
 /// @file    02_unamed_pipe.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
using std::cout;
using std::endl;

int main()
{
	int fds[2] = {0};
	pipe(fds);
	char buf[32] = {'\0'};
	if(fork() == 0)//子进程
	{
		close(fds[1]);//子进程关闭写端
		sleep(2);
		if(read(fds[0], buf, sizeof(buf)) > 0)
			puts(buf);
		close(fds[0]);//子进程关闭读端
		exit(0);
	}else//父进程
	{
		close(fds[0]);//关闭读端
		write(fds[1], "hello", 6);
		waitpid(-1, NULL, 0);//等待子进程关闭读端
		close(fds[1]);
		exit(0);
	}
	return 0;
}
