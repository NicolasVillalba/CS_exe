 ///
 /// @file    01_fwrite.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

int main()
{
	char buf[] = {"aaaa bbbb  aaaa cccc"};
	FILE * fp = popen("wc -w", "w");
	fwrite(buf, sizeof(buf), 1, fp);
	pclose(fp);
	return 0;
}
