 ///
 /// @file    const_pointer.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 /// @date    2016-04-16 10:30:27
 ///
 
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	
	int b = 20;

	//定义常量，必须初始化
	const int a = 10;
	//相当于define a 0
	

	//常量指针，英文为pointer to const
	const int *pa = &a;
	cout << "*pa = " << *pa << endl;
//	*pa = 20;//常量的值不允许更改
	cout << "*pa = " << *pa << endl;
	pa = &b;	
	cout << "pa = " << pa << endl;

	
	//指针常量，英文为const pointer
	int ia = 5;
	int * const pb = &ia;
	cout << "*pb = " << *pb << endl; 
	*pb = 2;
	cout << "*pb = " << *pb << endl;
//	pb = &b;//不能更改
	cout << "pb = " << pb << endl;

	//const pointer to const
	const int * const pd = &ia;

	return 0;
}

