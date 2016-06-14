 ///
 /// @file    03_2_read_pipe.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
using std::cout;
using std::endl;
int main()
{
	int fdFifo = open("pipe", O_RDONLY);//打开管道文件，返回一个文件描述符
	if(fdFifo == -1)
	{
		perror("open failed !");
		return -1;
	}
	char buf[32] = {'\0'};
	if(read(fdFifo, buf, sizeof(buf)) > 0)//读取管道的内容，没有内容的话阻塞状态
		puts(buf);//输出读取到buf的管道内容
	else 
	{
		perror("read pipe failed!");
		close(fdFifo);
		return 0;
	}
	close(fdFifo);
	return 0;
}
