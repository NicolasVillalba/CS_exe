 ///
 /// @file    MutexLock.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include "MutexLock.h"
#include <pthread.h>
using std::cout;
using std::endl;

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


int main()
{
	MutexLock mutex;
	mutex.lock();
	mutex.unlock();
	return 0;
}
