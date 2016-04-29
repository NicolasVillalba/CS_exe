 ///
 /// @file    7_nestClassTemplate.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Outside
{
public:
    template<class R>
    class Inside
    {
       private:
             R r;
       public:
            Inside(R x)
                                 {
                r = x;
                                   }
            void disp() {cout << "Inside:" << r<< endl;}
    };

	Outside(T x):t(x)
	{}
	void disp()
	{
		cout << "Outside:";
		t.disp(); 
	}

private:
	Inside<T> t;
};


int main()
{
	Outside<int>::Inside<double> obin(3.5);
	obin.disp();

	Outside<int> obout(2);
	obout.disp();

	return 0;
}
