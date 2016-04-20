 //
 /// @file    computer.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 
#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class Computer
{
public://对外提供接口
//	构造函数作用：
//	1.给对象一个标识符
//	2.为对象数据成员开辟内存空间
//	3.完成对象数据成员的初始化
//	构造函数可以进行重载
	Computer()//类初始化的构造函数,默认构造函数
	{
		cout << "Computer()" << endl;
		int len = strlen("ASUS");
		_brand = new char[len + 1];
		strcpy(_brand, "ASUS");
		_price = 5000;
	}

	Computer(const char * brand, float fprice)
	{//有参数构造函数
		int len  = strlen(brand);
		brand = new char[len + 1];
		strcpy(_brand, brand);
		_price = fprice;
	}
	void setBrand(char * brand);//将数据更新

	void setPrice(float fprice)//成员函数定义：2种方法,方法1
	{

		_price = fprice;
	}

	void print()
	{
		cout << "brand: " << _brand << endl;
		cout << "price: " << _price << endl;
	}
	
	~Computer();
private://不可以在类外直接访问
	char * _brand;
	float _price;
};

Computer::~Computer()//析构函数
{
	delete [] _brand;
	cout << "~computer()" << endl;
}

void Computer::setBrand(char * brand)//类外成员函数进行声明
{
	strcpy(_brand , brand);
}

int main()
{
	int a;
	Computer pc1;//声明一个Computer对象
	pc1.print();
	return 0;
}
