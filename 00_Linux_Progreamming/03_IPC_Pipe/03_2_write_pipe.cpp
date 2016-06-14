 ///
 /// @file    03_2_write_pipe.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
using std::cout;
using std::endl;
int main()
{
	int fdFifo = open("pipe", O_WRONLY);//打开一个管道文件，返回一个文件操作符
	if(-1 == fdFifo)
	{
		perror("open failed");
		return -1;
	}
	int ret = write(fdFifo, "hello", 6);//向管道写入内容
	if(-1 == ret)
	{
		perror("write pipe failed!");
		return -1;
	}
	close(fdFifo);//关闭管道
	return 0;
}
