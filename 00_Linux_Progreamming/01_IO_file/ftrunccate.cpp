 ///
 /// @file    ftrunccate.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_WRONLY);
	int ret = ftruncate(fd,3);
	if(-1 == ret)
	{
		cout << "fruncate failed" << endl;
		return -1;
	}
	close(fd);
	return 0;
}
