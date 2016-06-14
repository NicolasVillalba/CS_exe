 ///
 /// @file    02_write.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;

int main()
{
	key_t key = ftok("11", 1);//1.写入端使用ftok函数获得key
	if(-1 == key)
	{
		perror("ftok");
		exit(-1);
	}
	int shmid = shmget(key, 1024, IPC_CREAT|0777);//2.写入端创建一共享内存段
	if(-1 == shmid)
	{
		perror("shmget");
		exit(-1);
	}
	char *pMap = (char*)shmat(shmid, NULL, 0);//3.获得共享内存段的首地址
	if((char*)-1 == pMap)
	{
		perror("shmat");
		exit(-1);
	}
	pMap[0] = 'w';//4.往共享内存段中写内容
	if(-1 == shmdt(pMap)) //5.关闭共享内存段
	{
		perror("shmdt");
		exit(-1);
	}
	return 0;
}
