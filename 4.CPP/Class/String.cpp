 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-02-29 11:04:19
 ///
 
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);

	~String();

	void print();
private:
	char * pstr_;
};


String::String()
//: pstr_(NULL)
{
	
#if 1
	cout << "String()" << endl;
	pstr_ = new char[1];
	pstr_[0] = '\0';
#endif
}

String::String(const char * pstr)
{
	cout << "String(const char *)" << endl;
	pstr_ = new char[strlen(pstr) + 1];
	strcpy(pstr_, pstr);
}

String::String(const String & rhs)
{
	cout << "String(const String &)" << endl;
	pstr_ = new char[strlen(rhs.pstr_) + 1]; 
	strcpy(pstr_, rhs.pstr_);
}

String & String::operator=(const String & rhs)
{
	if(this == &rhs)
	{	return *this;	}//1. 自复制

	delete [] pstr_; //2.释放现有已申请堆空间

	pstr_ = new char[strlen(rhs.pstr_) + 1];//3. 申请空间进行复制
	strcpy(pstr_, rhs.pstr_);
	return *this;
}

String::~String()
{
	delete [] pstr_;
}

void String::print()
{
	cout << pstr_ << endl;

	//cout << "print()" << endl;
}


int main(void)
{
	String s1;
	s1.print();

	String s2 = "Hello,world";
	String s3 = "wangdao";
	s2.print();
	s3.print();
	s2 = s3;
	s2.print();

	String s4 = s3;
	
	
	

}
