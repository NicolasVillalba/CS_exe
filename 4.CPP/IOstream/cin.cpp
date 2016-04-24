 ///
 /// @file    cin.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 
#include<iostream>
#include<string>

void printCin()
{
	std::cout << "bad = " << std::cin.bad() << std::endl;//系统级故障
	std::cout << "fail = " << std::cin.fail() << std::endl;//可以恢复的故障
	std::cout << "eof = " << std::cin.eof() << std::endl;//是否文件末尾
	std::cout << "good = " << std::cin.good() << std::endl//有效与否的流
		      << std::endl;
}


int main()
{
	int num;
	printCin();

	while(std::cin >> num)
	{
		std::cout << num << std::endl;
	}

	printCin();

	std::cin.clear();

	printCin();
	
//	std::cin.ignore(1024, '\n');

	std::string s1;
	std::cin >> s1;
	std::cout << s1 << std::endl;

	return 0;
}
