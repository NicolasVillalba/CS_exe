 ///
 /// @file    MutexLock.h
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
#ifndef __MY_MUTEX_LOCK_H__
#define __MY_MUTEX_LOCK_H__
class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
private:
	pthread_mutex_t _mutex;
};

#endif
