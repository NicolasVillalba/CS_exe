#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;


namespace wd
{
class MyThread : public Thread
{
public:
	void run()
	{
		int cnt = 10;
		srand(time(NULL));
		while(cnt > 0)
		{
			int num = rand()%100;
			cout << cnt << ": num = " << num << endl;
			--cnt;
			sleep(1);
		}
	}
};
}



int main()
{
	wd::Thread * pThread = new wd::MyThread;
	unique_ptr<wd::Thread> pThreadPtr(pThread);
	pThreadPtr->start();
	pThreadPtr->join();

	return 0;
}
