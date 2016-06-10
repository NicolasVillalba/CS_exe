 ///
 /// @file    2_id.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using std::cout;
using std::endl;

int main()
{
	printf("uid:%d	gid:%d	euid:%d	egid:%d\n", getuid(), getgid(), geteuid(), getegid());
	//getuid(),getgid(),真实用户id与真实组id，即Joe运行了这个程序，那么这个进程所属的用户id与组id就是joe了
	//geteuid(),getegid()，分别为有效用户id与有效组id，是内核对进程的访问权限检查的时所关注的id
	return 0;
}
