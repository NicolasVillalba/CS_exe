 ///
 /// @file    namespace.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 /// @date    2016-04-15 21:31:44
 ///
 
#include <iostream>
using std::cout;

namespace AverageJoe{
	int flag = 1;
}

namespace AverageJoeWang{
	bool flag = false;
}


int main(int argc, char* argv[])
{
	if(AverageJoeWang::flag)
		cout << "Hello World" << std::endl;
	else
		cout << "AverageJoe is " << AverageJoe::flag << std::endl;
	return 0;
}
