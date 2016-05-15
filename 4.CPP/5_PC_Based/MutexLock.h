#ifndef __MY_MUTEXLOCK_H__
#define __MY_MUTEXLOCK_H__
#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class MutexLock : Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
	pthread_mutex_t * getMutexPtr();
private:
pthread_mutex_t _mutex;
bool _isLocked;
};
}
#endif
