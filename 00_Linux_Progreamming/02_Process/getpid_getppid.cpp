 ///
 /// @file    getpid_getppid.cpp
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
	printf("pid:%d,	ppid:%d\n", getpid(), getppid());
	return 0;
}
