#ifndef __MY_THREAD_H__
#define __MY_THREAD_H__
#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace wd
{
class Thread : Noncopyable
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();
	
	void start();
	void join();

	void setThreadCallback(ThreadCallback cb);
	static void * threadFunc(void * arg);
private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallback _cb;
};
}
#endif
