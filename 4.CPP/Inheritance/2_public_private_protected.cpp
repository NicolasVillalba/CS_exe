 ///
 /// @file    2_public_private_protected.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
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
		cout << "Point()" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	
	int calSum()
	{
		return x + y;
	}
	int getX()//类对象不能直接访问私有的数据成员，只能通过公有的函数成员获取私有数据成员
	{
		return x;
	}

	int getY()
	{
		return y;
	}
private:
	int x;
	int y;
};


class Point3D:public Point
{
public:
	Point3D(int a, int b, int c)
	:Point(a, b)
	{
		z = c;
		cout << "Point3D(int a, int b, int c)" << endl;
	}
	
	int getZ()
	{
		return z;
	}

	int calSum()
	{
//		return x + y + z;//public继承在子类中不能直接访问基类的private数据成员
		return getX() + getY() + z;
	}
	~Point3D()
	{
		cout << "~Point3D()" << endl;
	}
private:
	int z;
};



class Point4D:private Point
{
public:
	Point4D(int a, int b, int c, int d)
	:Point(a, b)
	{
		z = c;
		q = d;
		cout << "Point4D(int a, int b, int c, int d)" << endl;
	}
	
	int getZ()
	{
		return z;
	}

	int getQ()
	{
		return q;
	}

	int calSum()
	{
//		return x + y + z;//public继承在子类中不能直接访问基类的private数据成员
		return getX() + getY() +  z + q;
	}
	~Point4D()
	{
		cout << "~Point4D()" << endl;
	}

	void disp()
	{
		cout << "(" << getX() << ", " << getY() << ", " << getZ()<< ", " << getQ() <<")" << endl;//private继承类对象不能调用基类的成员函数
	}
private:
	int z;
	int q;
};

int main()
{
	Point p1(10, 20);
	cout << "p1 = " << "(" << p1.getX() << ", " <<p1.getY() << ")" << endl;

	Point3D pp1(1, 2, 3);
	cout << "pp1 = " << "(" << pp1.getX() << ", " <<pp1.getY() << ", " << pp1.getZ()<<")" << endl;//public继承类对象能调用基类的成员函数
	//return 0;

	Point4D ppp1(6 ,7, 8, 9);
	ppp1.disp();
	cout << ppp1.calSum() << endl;
	return 0;
}
