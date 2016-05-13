 ///
 /// @file    function.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

struct Foo
{
	Foo(int num)
	: _num(num)
	{}

	void print_add(int idx)
	{
		cout << _num + idx << endl;
	}

	
	int _num;

};


void print_num(int idx)
{
	cout << idx << endl;
}

struct PrintNum
{
	void operator()(int idx)
	{
		cout << idx << endl;
	}
};


int main()
{
	std::function<void(int)> f1 = print_num;//
	f1(1);

	std::function<void(Foo *, int)> f2 = &Foo::print_add;
	Foo foo(4);
	f2(&foo,1);
	cout << endl;
	return 0;
}
