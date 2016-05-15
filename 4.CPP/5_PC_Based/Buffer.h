#ifndef __MY_BUFFER_H__
#define __MY_BUFFER_H__
#include "MutexLock.h"
#include "Condition.h"
#include <queue>
using std::queue;

namespace wd
{
class Buffer
{
public:
	Buffer(int size);

	void push(int num);
	int pop();

	bool empty();
	bool full();
private:
	MutexLock _mutex;
	Condition _notEmpty;
	Condition _notFull;
	int _queSize;
	queue<int> _que;
};
}
#endif
