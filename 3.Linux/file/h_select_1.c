#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define FILENAME1 "a.txt"
#define FILENAME2 "dir.c"
int main()
{
    	char buf[10] = {0};
	
    	int fd1 = open(FILENAME1,O_RDWR);
   	int fd2 = open(FILENAME2,O_RDWR);
    	int fd3 = open(FILENAME1,O_RDWR);
    	int fd4 = open(FILENAME2,O_RDWR);
	
    	if( (-1 == fd1) || (-1 == fd2) || (-1 == fd3) || (-1 == fd4) )
    	{
        	perror("open");
        	exit(-1);
    	}
	
    	fd_set fdrd,fdwr;		//绑定读写集合
	
    	FD_ZERO(&fdrd);			//清除以前读的绑定
    	FD_ZERO(&fdwr);			//清除以前写的绑定
	
    	FD_SET(fd1,&fdrd);		//将fd1与读绑定
    	FD_SET(fd2,&fdrd);
    	FD_SET(fd3,&fdwr);		//将fd3与写绑定
    	FD_SET(fd4,&fdwr);
	
    	int max1 = fd1 > fd2 ? fd1 : fd2;		//获取读绑定中的文件描述词最大值
    	int max2 = fd3 > fd4 ? fd3 : fd4;    	//获取写绑定中的文件描述词最大值
    	int max = max1 > max2 ? max1 : max2;		//获得读写文件描述词最大值
	
    	struct timeval tv;		//用于记录时间，表示过这么长时间不响应就退出
    	tv.tv_sec = 2;			//秒
    	tv.tv_usec = 0;			//微妙
	
    	while(1)
    	{
        	if( select(max+1, &fdrd, &fdwr, NULL, &tv) == -1 )	//从1—max+1查找
        	{
            	perror("select");
            	break;
        	}
		
        	if( FD_ISSET(fd1,&fdrd) )	//如果fd1设置的是读绑定
        	{
            	read(fd1,buf,sizeof(buf)-1);
            	puts(buf);
            	sleep(1);
        	}
		
        	if( FD_ISSET(fd2,&fdrd) )
        	{
            	read(fd2,buf,sizeof(buf)-1);
            	puts(buf);
            	sleep(1);
        	}
		
        	if( FD_ISSET(fd3,&fdwr) ) 	//如果fd3设置的是写绑定
        	{
            	write(fd3,buf,sizeof(buf));
            	sleep(2);
        	}
		
        	if( FD_ISSET(fd4,&fdwr) )
        	{
            	write(fd4,buf,sizeof(buf));
            	sleep(2);
        	}
    	}	
    	close(fd1);
    	close(fd2);
    	close(fd3);
    	close(fd4);
}
