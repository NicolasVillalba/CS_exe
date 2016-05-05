 ///
 /// @file    3_multi_Inheritace.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	void disp()
	{
		cout << "A::disp()" << endl;
	}
};


class B
{
public:
	void disp()
	{
		cout << "B::disp()" << endl;
	}
};

class C:public A, public B
{
public:
	void print()
	{
		A::disp();//防止多基继承的二义性
	}

	void disp()
	{
		if(0) A::disp();
		else B::disp();
	}
};


int main()
{
	C c;
	c.print();

	c.B::disp();
	c.disp();

	return 0;
}
