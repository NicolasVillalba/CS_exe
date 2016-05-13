 ///
 /// @file    2_pthread_join.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

void * pfunc(void * p)
{
	cout << "thread create success" << endl;
	pthread_exit((void*)20);
}


int main()
{
	pthread_t pth_id;
	int ret;
	ret = pthread_create(&pth_id, NULL, pfunc, NULL);
	if(ret != 0)
	{
		cout << "pthread_create failed" << endl;
		return -1;
	}

	cout << "I am  a main thread!" << endl;
	int i;
	ret = pthread_join(pth_id, (void**)&i);
	if(ret != 0)
	{
		cout << "pthread_join failed , ret = " << ret << endl;
		return -1;
	}
	cout << "i = " << i << endl;
	return 0;
}
