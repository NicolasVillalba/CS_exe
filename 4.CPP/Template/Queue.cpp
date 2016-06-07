 ///
 /// @file    Queue.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class T, int num>
class Queue
{
private:
	T sz[num];//数据存储
	int front;//对头指针
	int rear;//队尾指针
public:
	Queue();
	~Queue();
	bool isEmpty();
	bool isFull();
	bool in_Queue(const T & x);
	bool pop_Queue(T & a);
};

template<class T, int num>
Queue<T, num>::Queue()
{
	front = -1;
	rear = -1;
}

template<class T, int num>
Queue<T, num>::~Queue()
{}

template<class T, int num>
bool Queue<T, num>::isEmpty()
{
	return (front == -1 && rear == -1);
}

template<class T, int num>
bool Queue<T,num>::isFull()
{
	return ((rear-front) == num);
}

template<class T,int num>
bool Queue<T,num>::in_Queue(const T & x)
{
	if(isFull())
		return false;
	else{
		rear++;		
		sz[rear] = x;
		return true;
	}
}

template<class T, int num>
bool Queue<T,num>::pop_Queue(T & a)
{
	if(isEmpty()|| front == rear)
		return false;
	else
	{
		front++;
		a = sz[front];
		return true;
	}
}


int main()
{
	Queue<int, 10> q;
	cout << "开始时候q是否为空" << q.isEmpty() << endl;

	q.in_Queue(10);
	cout << "开始时候q是否为空" << q.isEmpty() << endl;
//	int ss = 0;
//	q.pop_Queue(ss);
//	cout << ss <<endl;

	for(int i = 1; i < 10; i++)
	{
		q.in_Queue(i);
	}
	cout << "开始时候q是否为满" << q.isFull() << endl;


	int ss = 0;
	while(q.isEmpty())
	{	
		q.pop_Queue(ss);
		cout << ss << " ";
	}
	cout << endl;

	return 0;
}
