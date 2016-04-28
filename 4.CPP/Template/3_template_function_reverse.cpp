 ///
 /// @file    3_template_class.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
 
 //函数重载
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T func(T t)
{
        return t;
}

template <typename T>
int func(int i, T t)
{
        return i*t;
}

//=================================
template <typename T>
T max(T x, T y);

int max(int x, int y)
{
        return x>y?x:y;
}


template <typename T>
T max(T x, T y)
{
        return x>y?x:y;
}



int main()
{
        cout << func(10) << endl;
        cout << func(10, 3) << endl;
        cout << max(100, 200) << endl;
        
        int intX = 1, intY = 2;
        double dblX = 3.8, dblY = 2.9;
        cout << max(intX, intY) << endl;
        //调用max(int, int)，当普通函数和函数模板进行重载时，会先调用普通函数
        cout << max<double>(dblX, dblY) << endl;//显式实例化
        cout << max('A', '8') << endl;//隐式实例化char类型
        
        return 0;
}
