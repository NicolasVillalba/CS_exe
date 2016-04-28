
#include <iostream>
using std::cout;
using std::endl;

//模板的声明与定义需要在一个文件
//否则进行模板参数推断时会出错
template <typename T>
T max(const T & a, const T & b)
{
        return a > b ? a : b;
}

int main()
{
        cout << max(1, 2) << endl;
        return 0;
}


