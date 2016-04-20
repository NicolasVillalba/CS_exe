 ///
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 

//复制构造函数
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
	
	//系统自动提供一个复制构造函数，如果不显式定义的话
	//为什么复制构造函数的参数必须是引用？？无限递归，不会产生新的对象占用内存
	Point(const Point & rhs)
	:_ix(rhs._ix)//复制构造函数初始化列表
	,_iy(rhs._iy)//此处是直接访问类中的数据成员
	{
		cout << " const point & rhs" << endl;
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

	Point pt2 = pt1;//只运行一次构造函数
	pt2.print();
	return 0;
}
