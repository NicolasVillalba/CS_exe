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
	return 0;
}
