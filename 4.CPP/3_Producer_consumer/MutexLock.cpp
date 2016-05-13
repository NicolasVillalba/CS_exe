#include "MutexLock.h"

namespace wd
{
MutexLock::MutexLock()
: _isLocked(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
	_isLocked = false;
}


void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocked = true;
}

void MutexLock::unlock()
{
	pthread_mutex_destroy(&_mutex);
	_isLocked = false;
}

pthread_mutex_t * MutexLock::getMutexPtr()
{
	return &_Mutex;
}

}

