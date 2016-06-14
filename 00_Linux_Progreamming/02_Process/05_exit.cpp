 ///
 /// @file    05_exit.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using std::cout;
using std::endl;

int main()
{
	printf("Using exit..\n");
	printf("This is the content in buffer\n");
	exit(0);//调用exit函数，后面将不再执行，退出前清理I/O缓冲
	printf("Hello");
	return 0;
}
