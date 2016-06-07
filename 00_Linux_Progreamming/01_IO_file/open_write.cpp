 ///
 /// @file    open_write.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <strings.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
using std::cout;
using std::endl;


int main(int argc, char * argv[])
{
	int fd;
	fd = open("./a.txt", O_RDWR|O_CREAT);
	if(-1 == fd)
	{
		perror("open fail\n");
		return -1;
	}

	int ret;
	char buf[128];
	bzero(buf, sizeof(buf));
	ret = read(fd, buf, sizeof(buf));	
	if(-1 == ret)
	{
		perror("read fail\n");
		return -1;
	}else cout << buf << endl;
	close(fd);


	int fd2 = open("./b.txt", O_RDWR|O_CREAT);
	if(-1 == fd2)
	{
		perror("open2 fail\n");
		return -1;
	}

	bzero(buf, sizeof(buf));
	strcpy(buf, "how are you?");

	ret = write(fd2, buf, sizeof(buf));
	if(-1 == ret)
	{
		perror("write fail\n");
		return -1;
	}else cout << "write success!" << endl;
	close(fd2);
	return 0;
}
