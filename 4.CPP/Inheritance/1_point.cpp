#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
		cout << "Point(int a = 0, int b = 0)" << endl;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int x;
	int y;
};


//public继承，子类对象能够调用基类的成员函数
//private继承，子类对象不能够调用基类的成员函数

class Point3D:private Point //继承分public, private，protected,默认是private的
{
public:
	Point3D(int a, int b, int c = 0)
	: Point(a, b)
	{
		z = c;
		cout << "Point3D(int a, int b, int c)" <<endl;
	}

	int getZ()
	{
		return z;
	}

	int CalSum()
	{
		return getX() + getY()+z;
	}
	
	~Point3D()
	{
		cout << "~Point3D()" << endl;
	}
private:
	int z;
};


int main()
{
	Point p1;
	Point p2(2, 3);
	cout << "(" << p2.getX() << ", " << p2.getY() << ")" << endl;
	
	Point3D pp2(1, 2, 3);
//	cout << "(" << pp2.getX() << ", " << pp2.getY() << ", " << pp2.getZ() << ")" <<endl;
	cout << "getZ() = " << pp2.getZ() <<endl;

	cout << pp2.CalSum() << endl;

	return 0;
}
