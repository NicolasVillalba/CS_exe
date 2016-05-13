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
		_isRunning = false;//暂停运行
		pthread_detach(_pthId);//将线程描述符交给系统处理，然后销毁自身
	}
}

void Thread::start()//线程开始运行
{
	pthread_create(&_pthId, NULL, &Thread::threadFunc, this);//创建线程
	_isRunning = true;//线程运行中
}


void Thread::setThreadCallback(ThreadCallback cb)
{
	_cb = cb;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId, NULL);//等待线程退出
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
