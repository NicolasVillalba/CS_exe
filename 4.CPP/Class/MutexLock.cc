#include "MutexLock.h"
#include <pthread.h>
#include <iostream>


MutexLock::MutexLock()
{
	pthread_mutex_init(&_mutex, NULL);
}



MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}

pthread_mutex_t * MutexLock::getMutexPtr()
{
	return &_mutex;
}

