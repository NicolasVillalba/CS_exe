
## 一.概述

> 是一个由程序设计者命名的内存区域，程序设计者可以根据需要指定一些有名字的空间域，把一些全局实体分别放在各个命名空间中，从而与其他全局实体分隔开。

<!--more-->


## 二.使用方法

#### 1.第一种使用方法，先利用using声明，后直接使用

+ 定义**匿名**与**非匿名**命名空间

```cpp
namespace {
    int flag = 100;
}//匿名命名空间定义

namespace AverageJoe{
    bool false = false;
}
```

+ 声明命名空间，2种方法

```cpp
using namespace std;//这种方法不是很推荐
using std::cout;//比较推荐这这个声明命名空间中的变量
```

#### 2.第二种使用方法，直接利用**命名空间**加**作用域限定符**访问成员

```cpp
cout << "AverageJoe is " << AverageJoe::flag << std::endl;
```

#### 3.例子

+ 以下例子编写2个不同名字的命名空间

+ 在不同的命名空间对一个量定义不同类型和初始化

+ 利用不同的命名空间使得相同名字的变量不会产生冲突

```cpp
#include <iostream>
using std::cout;//第一种使用方法，先声明，后直接使用

namespace AverageJoe{
	int flag = 1;
}//end of namespace AverageJoe

namespace AverageJoeWang{
	bool flag = false;
}end of namespace AverageJoeWang

int main(int argc, char* argv[])
{
	if(AverageJoeWang::flag)
		cout << "Hello World" << std::endl;//第二种使用方法，直接利用**命名空间**加**作用域限定符**访问成员
	else
		cout << "AverageJoe is " << AverageJoe::flag << std::endl;
	return 0;
}
```




