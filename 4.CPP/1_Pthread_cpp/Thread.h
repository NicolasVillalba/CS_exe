#ifndef __MY_THREAD_H__
#define __MY_THREAD_H__

#include <iostream>
#include <pthread.h>
#include "Noncopyable.h"
using std::cout;
using std::endl;

namespace wd
{

class Thread : private Noncopyable
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

	virtual void run() = 0;

	static void * threadFunc(void * arg);//static去掉this指针
private:
	pthread_t _pthId;
	bool _isRunning;
};

}//end of the wd

#endif
