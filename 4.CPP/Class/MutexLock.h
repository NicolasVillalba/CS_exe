#ifndef __MUTEX_LOCK_H__
#define __MUTEX_LOCK_H__


#include <iostream>

class MutexLock
{

public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();

	pthread_mutex_t * getMutexPtr();


private:
	pthread_mutex_t _mutex;
};

#endif
