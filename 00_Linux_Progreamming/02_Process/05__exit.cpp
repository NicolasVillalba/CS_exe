 ///
 /// @file    05__exit.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
using std::cout;
using std::endl;

int main()
{
	printf("Using _exit ...\n");
	printf("This is the content in buffer");//没有\n的话，这个是存在缓冲区里面的
	_exit(0);//调用_exit函数，后面语句不执行
	printf("hello");
}
//因为_exit不会像exit退出清理缓冲区，输入结果只有第一个printf的内容
