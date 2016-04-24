 ///
 /// @file    cin1.cpp
 /// @author  AverageJoeWAng(AverageJoeWang@gmail.com)
 
#include<iostream>
#include<string>
#include<limits>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a;
	while(cin >> a, !cin.eof())
	{
		if(cin.bad())
		{
			cout << "IO stream corrupted !" << endl;
			return -1;
		}else if(cin.fail())
		{
			cout << "data illegal, please try again!" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		cout << "a = " << a << endl;
	}
	return 0;
}
