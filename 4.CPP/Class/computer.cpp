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
		strcpy(_brand, "ASUS");
		_price = 5000;
	}

	Computer(const char * brand, float fprice)
	{
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

private://不可以在类外直接访问
	char _brand[20];
	float _price;
};

void Computer::setBrand(char * brand)//类外成员函数进行声明
{
	strcpy(_brand , brand);
}

int main()
{
	int a;
	Computer pc1;//声明一个Computer对象
	pc1.print();
	Computer pc2("MacBook Pro", 10000);//使用有参数的构造函数
	pc2.print();
	return 0;
}
