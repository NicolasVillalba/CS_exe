 ///
 /// @file    lseek.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_WRONLY|O_CREAT);
	if(-1 == fd)
	{
		perror("open");
		return -1;
	}
	int ret = lseek(fd, 1024, SEEK_SET);
	if(-1 == ret)
	{
		perror("lseek");
		close(fd);
		return -1;
	}else
	{
		cout << "lseek success" << endl;
	}
	ret = write(fd, "ss", sizeof("ss"));
	if(-1 == ret)
	{
		perror("write");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}
