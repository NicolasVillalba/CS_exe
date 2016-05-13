#include "Thread.h"


namespace wd
{

Thread::Thread()//构造函数
: _pthId(0)
, _isRunning(false)
{}

Thread::~Thread()//析构函数
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
		pThread->run();
	}
}

}
