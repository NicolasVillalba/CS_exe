#ifndef __MY_THREAD_H__
#define __MY_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class Thread : Noncopyable
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();

	virtual void run()=0;

	static void * threadFunc(void * arg);
private:
	pthread_t _pthId;
	bool _isRunning;
};
}

#endif
