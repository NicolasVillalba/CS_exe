 ///
 /// @file    5_class_template.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
 
#include <iostream>
using namespace std;

//类模板
template <class T, int num>
class Stack
{
private:
        T sz[num];
        int point;
public:
        Stack()
                     {
                      point = 0;
                     }
                     
        bool isEmpty();
        bool isFull();
        bool push(const T&);
        bool pop(T&);
        int &GetPos()
                      {
                        return point;
                      }
};


template<class T, int num>
bool Stack<T, num>::isEmpty()
{
        return point == 0;
}

template<class T, int num>
bool Stack<T, num>::isFull()
{
        return point == num;//当point为num时,说明已经满了数组
}

template<class T, int num>
bool Stack<T, num>::push(const T& obt)
{
        if(isFull()) return false;
        else
                      {
                        sz[point] = obt;
                        point++;
                        return true;
                      }
}

template<class T, int num>
bool Stack<T, num>::pop(T &obt)
{
        if(isEmpty()) return false;
        else
                     {
                        point--;
                        obt = sz[point];
                        return true;
                      }
}


int main()
{
        Stack<int , 10> st;
        cout << "开始时st是否为空" << st.isEmpty() << endl;
        
        st.push(5);
        cout << "此时st是否为空？" << st.isEmpty() << endl;
        
        for(int i = 0; i< 10; i++)
                      {
                        st.push(i);
                       }
         cout << "此时st是否已满？" << st.isFull() << endl;
         
         int rec = 0;
         while(st.pop(rec))
                cout << rec << " ";
        cout << endl;
        
        return 0;
}
