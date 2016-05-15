#include "Thread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;


struct Producer
{
	void run(wd::Buffer & buff)
	{
		::srand(::time(NULL));
		while(1)
		{
			int num = ::rand() % 100;
			cout << "produce a num: " << num << endl;
			buff.push(num);
			::sleep(1);
		}
	}
};

struct Consumer
{
	void run(wd::Buffer & buff)
	{
		while(1)
		{
			int num = buff.pop();
			cout << "consume a num: " << num << endl;
			sleep(2);
		}
	}
};


int main(void)
{
	wd::Buffer buffer(10);
	Producer producer;
	Consumer consumer;
	std::function<void()> f1 = 
		std::bind(&Producer::run, &producer, std::ref(buffer));
	std::function<void()> f2 = 
		std::bind(&Consumer::run, &consumer, std::ref(buffer));
	wd::Thread producerThread(f1);
	wd::Thread consumerThread(f2);

	producerThread.start();
	consumerThread.start();
	producerThread.join();
	consumerThread.join();

	return 0;
}
