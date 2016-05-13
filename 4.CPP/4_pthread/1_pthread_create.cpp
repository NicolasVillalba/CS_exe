 ///
 /// @file    1_pthread_create.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using std::cout;
using std::endl;

void * pfunc(void *p)
{
	cout << "thread create success" << endl;
	return (void*)0;
}



int main()
{
	pthread_t pth_id;//线程描述符
	int ret;//返回值
	ret = pthread_create(&pth_id, NULL, pfunc, NULL);//pfunc是需要处理的事情函数
	if(ret != 0)
	{
		cout << "pthread_create failed!" << endl;
		return -1;
	}
	sleep(1);
	cout << "I am a main thread" << endl;
	return 0;
}
