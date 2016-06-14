
 ///
 /// @file    04_Orphaned.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <unistd.h>
#include <stdio.h>
using std::cout;
using std::endl;

int main()
{
	unlink("pipe");
	return 0;
}
