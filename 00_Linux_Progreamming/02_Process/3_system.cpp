 ///
 /// @file    3_system.cpp
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
	system("ls -l");//直接调用linux相关命令
	sleep(1);
	system("clear");
	return 0;
}
