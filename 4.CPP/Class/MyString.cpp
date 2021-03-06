 ///
 /// @file    MyString.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cout;
using std::endl;
using std::ostream;

class String
{
	friend ostream & operator<<(ostream & os, const String & rhs);

	class CharProxy
	{
	public:
		CharProxy(String & str, int idx);

		char & operator=(char ch);
		//CharProxy& operator=(char ch);
		//void operator=(char ch);

		//friend ostream & operator<<(ostream & os, const CharProxy & rhs);
		operator char();

	private:
		String & _str;
		int _idx;
	};

	//friend ostream & operator<<(ostream & os, const CharProxy & rhs);
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();

	//char & operator[](int idx);
	const char & operator[](int idx) const;
	CharProxy operator[](int idx);
	
	int use_count();
	int size();
	void print();
private:
	void increaseUseCount();
	void decreaseUseCount();
private:
	char * _pstr;
};


String::String()
{
	cout << "String()" << endl;
	_pstr = new char[2];
	_pstr[1] = 1;
}

String::String(const char * pstr)
{
	cout << "String(const char * pstr)" << endl;
	_pstr = new char[strlen(pstr) - 1];
	strcpy(_pstr, pstr);
	_pstr[size() + 1] = 1;
}

String::String(const String & rhs)
:_pstr(rhs._pstr)
{
	cout << "String(const String & rhs)" << endl;
	increaseUseCount();
}

String & String::operator = (const String & rhs)
{
	cout << "String & String::operator = (const String & rhs)" << endl;
	if(this != &rhs)
	{
		decreaseUseCount();
		if(use_count() == 0)
		{
			delete [] _pstr;
		}
		_pstr = rhs._pstr;
		increaseUseCount();
	}
	return *this;
}

String::~String()
{
	decreaseUseCount();
	if(use_count() == 0)
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
}


char & String::CharProxy::operator = (char ch)
{
	cout << "CharProxy::operator = (char ch)" << endl;
	static char nullchar = '\0';
	if(_idx > -1 && _idx < _str.size())
	{
		if(_str.use_count() > 1)
		{
			_str.decreaseUseCount();
			char * ptmp = new char [_str.size() + 2];
			strcpy(ptmp, _str._pstr);
			_str._pstr = ptmp;
			_str._pstr[_str.size() + 1] = 1;

			_str._pstr[_idx] = ch;
			return _str._pstr[_idx];
		}else if(_str.use_count() == 1)
		{
			_str._pstr[_idx] = ch;
			return _str._pstr[_idx];
		}
	}else{
		cout << "下标越界" << endl;
	}
}


void String::print()
{
	printf("pstr = %p\n", _pstr);
}

void String::increaseUseCount()
{
	++_pstr[size() + 1];
}

void String::decreaseUseCount()
{
	--_pstr[size() + 1];
}
int String::use_count()
{
	return _pstr[size()+ 1];
}

int String::size()
{
	return strlen(_pstr);
}

ostream & operator<<(ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}
int main(void)
{
	String s0;
	cout << "s0's use_count = " << s0.use_count() << endl;
	String s1 = "Hello";
	String s2 = "World";
	String s3 = s2;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;
	
	s3 = s1;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;

	cout << endl;
	//写操作
	s3[0] = 'h';
	//a = b = c = 'c';
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;

	String s4 = s3;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;
	cout << "s4's use_count = " << s4.use_count() << endl;

	//读操作
	cout << endl;
	cout << s4[0] << endl;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s1's use_count = " << s1.use_count() << endl;
	cout << "s2's use_count = " << s2.use_count() << endl;
	cout << "s3's use_count = " << s3.use_count() << endl;
	cout << "s4's use_count = " << s4.use_count() << endl;
	cout << "s3's address:";
	s3.print();
	cout << "s4's address:";
	s4.print();
}
