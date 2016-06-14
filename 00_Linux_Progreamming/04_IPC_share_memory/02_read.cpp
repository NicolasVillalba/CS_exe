 ///
 /// @file    02_read.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
using std::cout;
using std::endl;

int main()
{
	key_t key = ftok("11", 1);//1.读入端用ftok函数获得key
	if(-1 == key)
	{
		perror("ftok");
		exit(-1);
	}
	int shmid = shmget(key, 1024, 0777|IPC_CREAT);//2.读入端用shmget函数打开共享内存段
	if(-1 == shmid)
	{
		perror("shmget");
		exit(-1);
	}
	char *pMap = (char*)shmat(shmid, NULL, 0);//3.获取共享内存段的首地址
	printf("receive the data:%s\n", pMap);//4.读取共享内存段中的内容
	if(-1 == shmctl(shmid, IPC_RMID, 0))//5.删除共享内存段
	{
		perror("shmctl");
		exit(-1);
	}
	return 0;
}
