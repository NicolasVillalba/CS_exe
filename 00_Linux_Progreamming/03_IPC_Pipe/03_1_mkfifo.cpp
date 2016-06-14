 ///
 /// @file    03_1_mkfifo.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
using std::cout;
using std::endl;

int main()
{
	int ret;
	ret = mkfifo("./pipe", 0666);
	if(-1 == ret)
	{
		perror("mkfifo create failed!\n");
		return -1;
	}else
		printf("success!\n");
	return 0;
}
