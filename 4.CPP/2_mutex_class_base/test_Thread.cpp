#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

class Task
{
public:
	void doTask()
	{
		srand(time(NULL));
		int cnt = 10;
		while(cnt-- > 0)
		{
			int num = rand()%100;
			cout << cnt << ": num = "  << num << endl;
			sleep(1);
		}
	}
};

int main()
{
	Task task;
	wd::Thread thread(std::bind(&Task::doTask, &task));
	thread.start();
	thread.join();

	return 0;
}
