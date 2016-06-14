 ///
 /// @file    01_popen.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

int main()
{
	FILE * fp = popen("cat /etc/profile", "r");
	char buf[128] = {0};
	while(fgets(buf, sizeof(buf), fp))
	{
		puts(buf);
	}
	pclose(fp);
	return 0;
}
