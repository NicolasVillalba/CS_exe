 ///
 /// @file    point.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 
#include<iostream>

using std::cout;
using std::endl;

class Point
{
public:
	//初始化列表，构造函数，对象创建时自动调用
	Point() : _ix(0), _iy(0)//初始化过程
	{
		cout << "Point()" << endl;
	}
	
	//如果不显式定义析构函数时，系统自动为程序提供一个析构函数
	~Point()//析构函数，对象销毁时自动调用
	{	
		cout << "~point" << endl;
	}	

	void print()
	{
		cout << "(" << _ix << ", " << _iy << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};

int main()
{
	Point pt1;//pt1存储在栈上，是一个栈对象
	pt1.print();
	return 0;
}
