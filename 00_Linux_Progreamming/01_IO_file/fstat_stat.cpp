 ///
 /// @file    fstat_stat.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
using std::cout;
using std::endl;


int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDONLY);//fd存储的是文件描述符
	if(-1 == fd)
	{
		perror("open error");
		return -1;
	}
	
	struct stat buf;//创建一个文件的信息的结构体变量
	int ret = fstat(fd, &buf);
	if(-1 == ret)
	{
		perror("fstat error");
		close(fd);
		return -1;
	}
//获取文件类型，st_mode
	if(S_ISREG(buf.st_mode))
		cout << "It is a regular file!" << endl;
	else if(S_ISDIR(buf.st_mode))
		cout << "It is a dirent!" << endl;
	else if(S_ISLNK(buf.st_mode))
		cout << "It is a link file!" << endl;

	cout << "The size of the file is " << buf.st_size << endl; 

//获取文件的修改，创建等时间
	printf("atime = %d, mtime = %d, ctime = %d\n",buf.st_atime, buf.st_mtime, buf.st_ctime);

	struct tm *pt = gmtime(&(buf.st_atime));
	printf("%4d-%02d-%02d	%02d:%02d:%02d\n", (1900+pt->tm_year), (1+pt->tm_mon),
			pt->tm_mday,(8+pt->tm_hour), pt->tm_min, pt->tm_sec);

	return 0;
}
