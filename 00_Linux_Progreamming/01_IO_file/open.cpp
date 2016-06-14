 ///
 /// @file    open.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("error args");
		return -1;
	}

	int fd;
	fd = open(argv[1], O_RDWR|O_CREAT);
	if(-1 == fd)
	{	
		perror("open fail\n");
		return -1;
	}else 
		printf("open success !\n");
	close(fd);
	return 0;
}
