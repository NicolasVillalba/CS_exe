 ///
 /// @file    a_b_max.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename MaxNum>
MaxNum MAX(MaxNum a, MaxNum b)
{
	return a>b?a:b;
}

int main()
{
	cout << MAX(3, 4) << endl;
	cout << MAX(3.1, 8.2) << endl;
	return 0;
}
