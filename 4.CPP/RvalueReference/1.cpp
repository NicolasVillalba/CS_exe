 ///
 /// @file    1.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	int a = 10;
	int b = 120;
	int *pFlag = &a;
	vector<int> vctTemp;
	vctTemp.push_back(1);
	string str1 = "hello";
	string str2 = "world";
	const int &m = 1;

	//&(a+b); //右值
	int c = a+b;
	&(++a);//左值

	&pFlag;
	&(*pFlag);
}
