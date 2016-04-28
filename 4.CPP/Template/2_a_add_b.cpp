 ///
 /// @file    2_a_add_b.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//实例化
//函数模板 --> 模板函数
template <typename T>
T add(const T & lhs, const T & rhs)//模板
{
        return lhs + rhs;
}//调用add(4,6);//隐式实例化
//模板根据调用生成相应的代码，生产代码的过程叫做参数推断

template <typename T, int NUM>
T fun(T a)
{
        return a * NUM;
}//调用fun<int, 5>(4);显示实例化

int main()
{
        cout << add(10, 20) << endl;
        cout << add(1.2, 2.0) << endl;
        string s1("hello");
        string s2("world");
        cout << add(s1, s2) <<endl;
        cout << "===============" << endl;
        cout << fun<int, 4>(3) << endl;
        return 0;
}
