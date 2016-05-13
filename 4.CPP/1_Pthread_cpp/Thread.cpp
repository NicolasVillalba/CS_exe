#include "Thread.h"

namespace wd
{

Thread::Thread()
: _pthId(0)
, _isRunning(false)
{
}


Thread::~Thread()
{
	if(_isRunning)
	{
		_isRunning = false;
		pthread_detach(_pthId);//将线程交给系统
	}
}

void Thread::start()
{
	pthread_create(& _pthId, NULL, Thread::threadFunc, NULL);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId, NULL);
	}
}

void * Thread::threadFunc(void * arg)
{
	Thread * pThread = static_cast<Thread*>(arg);//强转
	if(pThread)
	{
		pThread->run();
	}
}

}//end of the wd
