 ///
 /// @file    io1.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <string>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printCin()
{
	cout << "bad = " << cin.bad() << endl;
	cout << "fail= " << cin.fail() << endl;
	cout << "eof = " << cin.eof() << endl;
	cout << "good = " << cin.good() << endl;
}

int main()
{
	printCin();

	int inum;

	while(cin >> inum)
	{
		cout << "inum = " << inum << endl;
	}
	printCin();
	cin.clear();//将输入流状态重置之后，还需要清空缓冲区

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << endl;

	printCin();//fail = 1可以恢复
	string s;
	cin >> s;
	cout << "s = " << s << endl;
	return 0;
}
