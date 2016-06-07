 ///
 /// @file    2_fstream.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;

int main()
{
	ifstream ifs("io2.cpp");
	if(!ifs.good())
	{
		cout << " ifstream open error!" << endl;
		return -1;
	}
	ofstream ofs("test.txt");
	if(!ofs.good())
	{
		cout << "ofstream open error !" << endl;
		return -1;
	}

	string str;
	while(ifs >> str)
	{
		ofs << str << endl;//输出到输出流
	}
	ifs.close();
	ofs.close();
	return 0;
}
