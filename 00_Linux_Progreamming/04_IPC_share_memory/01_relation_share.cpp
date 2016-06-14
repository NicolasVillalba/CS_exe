 ///
 /// @file    01_relation_share.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PERM S_IRUSR|S_IWUSR
using std::cout;
using std::endl;
//两个有亲属关系进程进行通信
int main(int argc, char* argv[])
{
	int shmid = shmget(IPC_PRIVATE, 1024, PERM);
	if(-1 == shmid)
	{
		fprintf(stderr, "Create share memory error: %s\n\a", strerror(errno));
		exit(1);
	}
	if(fork > 0)//父进程
	{
		char *p_addr = (char*)shmat(shmid, NULL, 0);//获取该段共享内存
		memset(p_addr, '\0', 1024);
		strncpy(p_addr, "share memory", 1024);
		printf("parent %d write buffer: %s\n", getpid(), p_addr);
		sleep(2);
		wait(NULL);//等待子进程，防止僵尸进程
		shmctl(shmid, IPC_RMID, 0);//删除共享内存，用ipcs -m查看共享内存
		exit(0);
	}
	else//子进程
	{
		sleep(5);
		char *c_addr = (char*)shmat(shmid, NULL, 0);//取出内容
		printf("Client pid = %d, shmid = %d, read buffer: %s\n", getpid(), shmid, c_addr);
		exit(0);
	}
	return 0;
}
