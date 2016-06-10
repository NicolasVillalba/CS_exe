 ///
 /// @file    03_exec1.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	int a = atoi(argv[1]);//字符转整型
	int b = atoi(argv[2]);//分别接收2个输入
	printf("%d + %d = %d", a,b,a+b);
	return 0;
}
