#include "Thread.h"

namespace wd
{
Thread::Thread(ThreadCallback cb)
: _pthId(0)
, _isRunning(false)
, _cb(cb)
{}

Thread::~Thread()
{
	if(_isRunning)
	{
		_isRunning = false;
		pthread_detach(_pthId);
	}
}

void Thread::start()
{
	pthread_create(&_pthId, NULL, &Thread::threadFunc, this);
	_isRunning = true;
}

void Thread::setThreadCallback(ThreadCallback cb)
{
	_cb = cb;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId, NULL);
		_isRunning = false;
	}
}


void * Thread::threadFunc(void * arg)
{
	Thread * pThread = static_cast<Thread*>(arg);
	if(pThread)
	{
		pThread->_cb();//执行回调函数
	}
}

}
