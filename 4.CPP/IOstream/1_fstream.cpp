 ///
 /// @file    1_fstream.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
	ifstream ifs("io1.cpp");
	if(!ifs.good())
	{
		cout << "ifstream open error" << endl;
		return -1;
	}

	string str;
//	while(ifs >> str)//利用空格分开
//		cout << str << endl;
	cout << "=====================" << endl;
	vector<string> strVec;
	while(getline(ifs, str))//整行读取
	{
		//cout << str << endl;
		strVec.push_back(str);
	}
	for(auto &ss : strVec)
		cout << ss << endl;
	return 0;
}
