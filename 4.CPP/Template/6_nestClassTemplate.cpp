//
 /// @file    6_nestClassTemplate.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//普通类模板
template<class T1, class T2>//类模板
class Convert
{
public:
        T2 f(T1 data)//此函数的返回值类型是T2，原始类型是T1
                      {
             return (T2)data;
                      }
};//将T1类型的数据转换成T2类型的



//嵌套类模板
template<class T1>
class Test
{
public:
        template<class T2>
        T1 f(T2 b)//模板成员函数定义
                      {
              return T1(b);//将b由T2类型强制转换成T1类型
                      }
};


int main()
{
        Convert<char, int> c1;
        cout << c1.f('A') << endl;
        
        Convert<float, int> c2;
        cout << c2.f(9.85f) << endl;
        
        Convert<int, short> c3;
        cout << c3.f(0x7fffffff) << endl;
        
        
        Test<int> t; 
        cout << t.f(3.14f) << endl;
        
        return 0;
}
