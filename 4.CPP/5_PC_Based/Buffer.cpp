#include "Buffer.h"

namespace wd
{

Buffer::Buffer(int size)
: _mutex()
, _notEmpty(_mutex)
, _notFull(_mutex)
, _queSize(size)
{}

bool Buffer::empty()
{
	return _que.empty();
}

bool Buffer::full()
{
	return _que.size() == _queSize;
}

void Buffer::push(int num)
{
	_mutex.lock();
	while(full())
	{
		_notFull.wait();
	}
	_que.push(num);
	_notEmpty.notify();
	_mutex.unlock();
}


int Buffer::pop()
{
	_mutex.lock();
	while(empty())
	{
		_notEmpty.wait();
	}
	int num = _que.front();
	_que.pop();
	_notFull.notify();

	_mutex.unlock();
	return num;
}

}
