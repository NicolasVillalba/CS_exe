 ///
 /// @file    06_Parent_fork.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::endl;

int main()
{
	char buf[32] = {'\0'};
	int fd = open("./a.txt",O_RDONLY);
	if(fork()>0)//父进程
	{
		close(fd);//关闭文件
		return 0;
	}
	//此时子进程自动继承了父进程打开的文件，继承以后父进程关闭打开的文件不会对子进程造成影响
	sleep(3);//给父进程时间关闭文件
	if(read(fd, buf, sizeof(buf)-1) < 0)//子进程读取
		perror("read fail");
	else
		printf("string : %s", buf);
	close(fd);
	return 0;
}
