#include "Thread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;


class ProducerThread : public wd::Thread
{
public:
	ProducerThread(wd::Buff & buf)
	: _buf(buf)
	{}

	void run()
	{
		srand(time(NULL));
		while(1)
		{
			int num = rand()%100;
			_buf.push(num);
			cout << "produce a num : " << num << endl;
			sleep(1);
		}
	}
private:
	wd::Buffer & _buf;
};

class ConsumerThread : public wd::Thread
{
public:
	ConsumerThread(wd::BUffer & buf)
	: _buf(buf)
	{}

	void run()
	{
		while(1)
		{
			int num = _buf.pop();
			cout << "Consume a num : " << num << endl;
			sleep(2);
		}
	}
private:
	wd::Buffer & _buf;
};


int main()
{
	wd::Buffer buffer(10);
	wd::Thread * pProduct = new ProducerThread(buffer);
	wd::Thread * pConsum = new ConsumerThread(buffer);
	pProduct->start();
	pConsum->start();
	pProduct->join();
	pConsum->join();

	return 0;
}
