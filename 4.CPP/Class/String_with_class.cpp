#include<iostream>
#include<string.h>

using std::cout;
using std::endl;

class String
{
private:
	char *pStr;

public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator = (const String & rhs);//赋值运算符函数
	~String();

	void print();
};


String::String()//默认构造函数
{
	cout << "String()" << endl;
	pStr = new char[strlen("AverageJoeWang") + 1];
	strcpy(pStr, "AverageJoeWang");
}

String::String(const char *pstr)//有参构造函数
{
	pStr = new char[strlen(pstr) + 1];
	strcpy(pStr, pstr);
	cout << "String(const char *)" << endl;
}

String::String(const String & rhs)//默认复制构造函数,深拷贝
{
	cout << "Computer(const String & rhs)" << endl;
	pStr = new char[strlen(rhs.pStr) + 1];//开辟空间
	strcpy(pStr, rhs.pStr);
}


String & String::operator = (const String & rhs)//赋值运算符函数
//String::应该在operator关键字前面，最后返回的是一个类的引用
{
	cout << "Computer & operator = (const Computer &)" << endl;
	if(this == &rhs) return *this;//1.自复制

	delete [] pStr;//2.释放已经申请的堆空间

	pStr = new char[strlen(rhs.pStr) + 1];//3.申请新的空间
	strcpy(pStr, rhs.pStr);//4.进行复制
	return *this;
}




String::~String()//析构函数，在作用域结束时程序自动调用
{
	delete [] pStr;
	cout << "~String()" << endl;
}


void String::print()//打印函数
{
	cout << "pStr = " << pStr << endl;
}


int main()
{
	String str1;
	String str2 = "Hello,world";
	String str3 = "wangdao";
	str2 = str3;
	String str4 = str3;

	str1.print();
	str2.print();
	str3.print();
	str4.print();


	return 0;
}
