 ///
 /// @file    swap.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 /// @date    2016-04-16 11:01:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void swap(int &a, int &b)//引用
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(int *a, int *b)//传递
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a= 3;
	int b = 4;
	swap(a, b);//引用函数
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}
