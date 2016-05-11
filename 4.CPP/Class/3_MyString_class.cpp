 ///
 /// @file    3_MyString_class.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <cstring>
using namespace std;

class String
{
friend ostream & operator<<(ostream &os, String &str);
public:
	String();
	String(const char *cp);

	String(const String &str);

	~String();

	String & operator=(const String &pstr);

private:
	char *_data;
};

String::String()//无参构造函数
{
	cout << "String()" << endl;
	_data = NULL;
	_data = new char[1];
	_data[0] = '\0';
}

String::String(const char *cp)//带参数的构造函数
{
	cout << "String(const char *cp)" <<endl;
	_data = new char[strlen(cp) + 1];
	strcpy(_data, cp);
}

String::~String()//析构函数
{
	cout << "String::~String()" <<endl;
	if(_data != NULL)
	{
		delete [] _data;
		_data = NULL;
	}
}



String::String(const String &str)//复制构造函数
{
	cout << "String(const String &str)" << endl;
	if(str._data == NULL)
		_data = NULL;
	else
	{
		_data = new char[strlen(str._data) + 1];
		strcpy(_data, str._data);
	}
}


String & String::operator=(const String &pstr)//赋值运算符函数
{
	cout << "String & String::operator=(const String &pstr)" << endl;
	if(this == &pstr)
		return *this;

	if(_data != NULL)
	{
		delete [] _data;
		_data = NULL;
	}
	_data = new char[strlen(pstr._data) + 1];
	strcpy(_data, pstr._data);
	return *this;
}

ostream & operator<<(ostream &os, String &str)//输出函数
{
	os<<str._data;
	return os;
}


int main()
{
	String s1;//调用无参构造函数
	cout << "s1 = " << s1 << endl;
	String s2("JoeWang");//调用有参构造函数
	cout << "s2 = " << s2 << endl;
	String s3 = s2;//调用复制构造函数
	cout << "s3 = " << s3 << endl;
	String s4("AverageJoeWang");//调用友残构造函数
	cout << "s4 = " << s4 << endl;
	s1 = s4;//调用赋值运算符函数
	cout << "s1 = " << s1 << endl;
	return 0;
}
