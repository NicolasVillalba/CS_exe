 ///
 /// @file    4_Virtual.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base  
{  
public:Base(){}  
public:  
       virtual void print(){cout<<"Base";}//虚函数  
};  
   
class Derived:public Base  
{  
public:Derived(){}  
public:  
       void print(){cout<<"Derived";}  
};  
   
int main()  
{  
       Base *point=new Derived();  
       point->print();  
}   
