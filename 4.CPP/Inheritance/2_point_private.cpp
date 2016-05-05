 ///
 /// @file    1_point.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;



class point
{
private:
	int xPos;
	int yPos;

public:
	point(int x = 0, int y = 0)
	{
		xPos = x;
		yPos = y;
	}

	void disp()
	{
		cout << "(" << xPos << "," << yPos << ")" << endl;
	}

	int GetX()
	{
		return xPos;
	}

	int GetY()
	{
		return yPos;
	}

	~point()
	{
		cout << "~point()" << endl;
	}
};


class point3D:private point //3维，从point类继承而来
{
private:
	int zPos;

public:
	point3D(int x, int y, int z)
	: point(x, y)//派生类构造函数，初始化表中调用基类构造函数
	{
		zPos = z;
		cout << "point3D(int x, int y, int z)" << endl;
	//派生类构造函数，初始化表中调用基类构造函数
	}

	void disp()//隐藏了基类中同名的disp函数
	{
		cout << "(" << GetX() << "," << GetY() << "," << zPos << ")" << endl;
	}

	int calcSum()//增加计算3个数据成员和的函数
	{
		return GetX()+GetY() + zPos;
	}
};


int main()
{
	point pt1(7 , 8);
	pt1.disp();

	point3D pt2(3, 4, 5);
	pt2.disp();

	int res = pt2.calcSum();//计算pt2中3个坐标信息的累加和
	cout << res << endl;

	return 0;
}
