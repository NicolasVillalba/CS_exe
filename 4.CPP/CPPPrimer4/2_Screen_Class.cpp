 ///
 /// @file    2_Screen_Class.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;



class Screen
{
public:

	typedef std::string::size_type index;

	Screen(index ht = 0, index wd = 0)
	: contents(ht*wd, 'A')
	, cursor(0)
	, height(ht)
	, width(wd)
	{}

	char get() const;

	char get(index r, index c) const
	{
		index row = r * width;
		return contents[row + c];
	}
private:
	string contents;
	index cursor;
	index height, width;
};


char Screen::get() const
{
	return contents[cursor];
}

int main()
{
	Screen s(10, 20);
	cout << "get() = " << s.get() << endl;
	cout << "get(10, 12) = " << s.get(10, 12) << endl;
	return 0;
}
