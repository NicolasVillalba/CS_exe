 ///
 /// @file    03_exec2.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using std::cout;
using std::endl;


int main()
{
	execl("./add.out", "add.out", "3", "4", NULL);
	return 0;
}
