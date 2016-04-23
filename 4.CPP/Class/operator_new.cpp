 ///
 /// @file    operator_new.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 

#include<iostream>
#include<stdlib.h>

using std::cout;
using std::endl;

class Student
{
private:
	int _iId;
	char _name[20];
public:
	Student()
	{
		cout << "Student()" << endl;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}

	static void * operator new(size_t sz)//编译器自动提供的函数
	{
		void *pRet = malloc(sz);
		return pRet;
	}

	static void operator delete(void *pRet)//编译器自动提供的函数
	{
		cout << "operator delete()" << endl;
		free(pRet);
	}
};


int main()
{
	Student *pStu = new Student;
	delete pStu;

	return 0;
}
