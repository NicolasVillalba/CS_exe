 ///
 /// @file    vector.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;

void printfVector(std::vector<int> & vecInt)
{
	cout << "vecInt's size :" << vecInt.size() << endl;
	cout << "vecInt's capacity:" << vecInt.capacity() << endl;
}

int main()
{
	std::vector<int> vecInt;
	//vector存储空间是动态增长，每次都是*2,
	//体是超过大小的时候重新申请空间，将原来的数据迁移到新的空间，释放原来的空间
//	vecInt.reserve(20);//开通一个20个空间
	printfVector(vecInt);
	vecInt.push_back(1);//添加函数
	printfVector(vecInt);
	vecInt.push_back(2);
	printfVector(vecInt);

	vecInt.push_back(2);
	printfVector(vecInt);
	vecInt.push_back(2);
	printfVector(vecInt);
	vecInt.push_back(2);
	printfVector(vecInt);
//	return 0;

	std::vector<int>::iterator it = vecInt.begin();//迭代器指针
	for(; it != vecInt.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "第二种迭代器" << endl;
	for(int idx = 0; idx != vecInt.size(); ++idx)
	{
		cout << vecInt[idx] << endl;
	}

	//cout << "第三种迭代器" << endl;
	//for(auto elem : vecInt)
	//{
	//	cout << elem << endl;
	//}//c++11
}
