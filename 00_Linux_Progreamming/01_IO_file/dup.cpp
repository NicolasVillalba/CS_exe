 ///
 /// @file    dup.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDONLY|O_CREAT);
	if(-1 == fd)
	{
		perror("open error");
		return -1;
	}
	char buf[128];
	bzero(buf, sizeof(buf));
	int fd2 = fd;//类似于C语言的指针，当释放close掉一个的时候，另一个已经不能操作
	int fd3 = dup(fd);//内核的文件打开引用计算+1，变成2，当一个释放的时候，另一个还是可以继续访问文件
	close(fd);
	printf("read : %d\n", read(fd3, buf, sizeof(buf)-1));
	close(fd3);
	return 0;
}
