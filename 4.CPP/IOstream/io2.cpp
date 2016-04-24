 ///
 /// @file    io2.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 
#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;


int main()
{
	ifstream ifs("cin.cpp");//创建一个流对象
	if(!ifs.good())
	{
		cout << "istream open error!" << endl;
		return -1;
	}


	string s;
#if 0
	while(ifs >> s)
	{
		cout << s <<endl;
	}
#endif
//以上为输出，以空格为一行

	while(getline(ifs, s))
	{
		cout << s << endl;
	}//按照原来的样子输出

//	cout << "execute" << endl;
	return 0;
}

