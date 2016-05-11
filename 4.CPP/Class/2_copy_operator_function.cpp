 ///
 /// @file    1_copy_structure_function.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <cstring>
using namespace std;


class computer
{
public:
	computer()
	{
		brand = NULL;
		price = 0;
	}//默认构造函数，这个是方便定义computer c1;
	computer(const char* sz, float p)
	{
		brand = new char[strlen(sz) + 1];
		strcpy(brand, sz);
		price = p;
	}

	computer(const computer &cp)
	{
		brand = new char[strlen(cp.brand) + 1];
		strcpy(brand, cp.brand);
		price = cp.price;
	}

	computer &operator=(const computer &cp)
	{
		if(this == &cp) return *this;
		price = cp.price;
		delete [] brand;
		brand = new char[strlen(cp.brand) + 1];
		if(brand != NULL)
			strcpy(brand, cp.brand);
		return *this;
	}
	
	~computer()
	{
		delete [] brand;
	}

	void print()
	{
		cout << "品牌：" << brand << endl;
		cout << "价格：" << price << endl;
	}
private:
	char *brand;
	float price;
};


int main()
{
	computer c2("lenove", 4000);
	c2.print();
	computer c3(c2);
	c3.print();
	computer c4 = c3;
	c4.print();
	computer c1;
	c1 = c2;
	c1.print();
	return 0;
}
