 ///
 /// @file    sprintf.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	char a[10] = "hello";
	char b[10] = "world";
	char c[128] = {0};
	int ret = sprintf(c, "%s %s", a, b);
	if(ret <= 0)
	{
		perror("sprintf\n");
	}
	printf("c = %s\n", c);
	return 0;
}
