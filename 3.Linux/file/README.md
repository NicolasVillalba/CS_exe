###1.文件描述符

> 内核为每个进程维护一个已打开文件的记录表，文件描述符是一个较小的正整数（0—1023），它代表记录表的一项，通过文件描述符和一组基于文件描述符的文件操作函数，就可以实现对文件的读、写、创建、删除等操作。常用基于文件描述符的函数有open（打开）、creat（创建）、close（关闭）、read（读取）、write（写入）、ftruncate（改变文件大小）、lseek（定位）、fsync（同步）、fstat（获取文件状态）、fchmod（权限）、flock（加锁）、fcntl（控制文件属性）、dup（复制）、dup2、select和ioctl。基于文件描述符的文件操作并非ANSI C的函数。

如果不清楚某个函数的具体实现形式，可以通过下面的方式查询man 函数名  查看该函数的帮助。



###2.打开/创建/操作文件



+ open和creat都能打开和创建函数，原型为

```c

#include <sys/types.h>   //头文件

#include <sys/stat.h>

#include <fcntl.h>

int open(const char *pathname, int flags);		//文件名  打开方式

int open(const char *pathname, int flags, mode_t mode);//文件名  打开方式  权限

int creat(const char *pathname, mode_t mode);	//文件名  权限   //现在已经不常用了

```

+ creat函数等价于open(pathname,O_CREAT|O_TRUNC|O_WRONLY,mode);



> open()函数出错时返回-1，相关参数如下：



+ flags和mode都是一组掩码的合成值，flags表示打开或创建的方式，mode表示文件的访问权限。



> flags的可选项有



|掩码	|含义|

|------------------|------------------------------|

|O_RDONLY|	以只读的方式打开|

|O_WRONLY	|以只写的方式打开|

|O_RDWRv|	以读写的方式打开|

|O_CREAT	|如果文件不存在，则创建文件|

|O_EXCL|	仅与O_CREAT连用，如果文件已存在，则强制open失败|

|O_TRUNC|	如果文件存在，将文件的长度截至0|

|O_APPEND|	已追加的方式打开文件，每次调用write时，文件指针自动先移到文件尾，用于多进程写同一个文件的情况。|

|O_NONBLOCK	|非阻塞方式打开，无论有无数据读取或等待，都会立即返回进程之中。|

|O_NODELAY	|非阻塞方式打开|

|O_SYNC	|同步打开文件，只有在数据被真正写入物理设备设备后才返回|



> 例子



```c


#include<stdio.h>

#include<sys/types.h>

#include<sys/stat.h>

#include<fcntl.h>

#include<stdlib.h>





int main(int argc, char* argv[])

{

    if(argc != 2)

    {

        printf("error args\n");

        return -1;

    }

    int fd;//第一个打开的是3,1和2的进程是stdin,stdout

    fd = open(argv[1], O_RDONLY|O_CREAT, 0666);

    if(fd == -1)

    {

         perror("open");

         return -1;

    }

    printf("fd is %d\n", fd);

    close(fd);

    return 0;

}




```



###3.读写文件



> 原型



```c

#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);//文件描述词  缓冲区  长度

ssize_t write(int fd, const void *buf, size_t count);

//对于read和write函数，出错返回-1，读取完了之后，返回0， 其他情况返回读写的个数。

```



> 例子



```c

#include<stdio.h>

#include<sys/types.h>

#include<sys/stat.h>

#include<fcntl.h>

#include<stdlib.h>

#include<unistd.h>





int main(int argc, char* argv[])

{

    if(argc != 2)

    {

        printf("error args\n");

        return -1;

    }

    int fd;//第一个打开的是3,1和2的进程是stdin,stdout

    fd = open(argv[1], O_RDONLY|O_CREAT, 0666);

    if(fd == -1)

    {

         perror("open");

         return -1;

    }

    printf("fd is %d\n", fd);

    char buf[128] = {0};

    int ret = read(fd, buf, sizeof(buf));

    if(ret == -1)

    {

        perror("read error");

        return -1;

    }

    printf("buf = %s\n", buf);

    close(fd);

    return 0;

}

```

###4.改变文件大小

> 例子

```c
//改变文件大小
//原型
//#include <unistd.h>
//int ftruncate(int fd, off_t length);
//参数fd为已打开的文件描述词，而且必须是以写入模式打开的文件。如果原来的文件大小比参数length大，则超过的部分会被删去。

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    int fd = open("aaa.txt", O_WRONLY);
    ftruncate(fd, 10);//10是一个界限，要是文件比10大，增多出来的删除
    close(fd);
    return 0;
}
```

###5.文件定位（lseek）

+ 函数lseek将文件指针设定到相对于whence，偏移值为offset的位置

```c
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);//fd文件描述词
```

> whence可以为以下三个常量

+ SEEK_SET  从文件头开始计算

+ SEEK_CUR  从当前指针开始计算

+ SEEK_END  从文件尾部开始计算

> 利用该函数可以实现文件空洞（对一个新建的空文件，可以定位到偏移文件开头1024个字节的地方，在写入一个字符，则相当于给该文件分配了1025个字节的空间，形成文件空洞）**通常用于多进程间通信的时候的共享内存**。


> 例子

```c
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
    int fd = open("d.txt", O_WRONLY|O_CREAT);
    lseek(fd, 1024, SEEK_SET);
    write(fd, "a", 1);
    close(fd);
    return 0;
}
```

###6.获取文件信息

+ 可以通过fstat和stat函数获取文件信息，调用完毕后，文件信息被填充到结构体struct stat变量中

> 原型为

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *file_name, struct stat *buf);  	//文件名  stat结构体指针
int fstat(int fd, struct stat *buf);  			//文件描述词   stat结构体指针

//其中结构体stat的定义为

struct stat {
           dev_t         st_dev;      /*如果是设备，返回设备表述符，否则为0*/
           ino_t         st_ino;      /* i节点号 */
           mode_t        st_mode;     /* 文件类型 */  无符号短整型
           nlink_t       st_nlink;    /* 链接数 */
           uid_t         st_uid;      /* 属主ID */
           gid_t         st_gid;      /* 组ID */
           dev_t         st_rdev;     /* 设备类型*/
           off_t         st_size;     /* 文件大小，字节表示 */
           blksize_t     st_blksize;  /* 块大小*/
           blkcnt_t      st_blocks;   /* 块数 */
           time_t        st_atime;    /* 最后访问时间*/
           time_t        st_mtime;    /* 最后修改时间*/
           time_t        st_ctime;    /* 最后权限修改时间 */
    };
```

> 说明

+ 结构体的成员st_mode，有一组宏可以进行文件类型的判断

|宏|	描述|
|-------------|-----------------|
|S_ISLNK(mode)	|判断是否是符号链接|
|S_ISREG(mode)	|判断是否是普通文件|
|S_ISDIR(mode)	|判断是否是目录|
|S_ISCHR(mode)	|判断是否是字符型设备|
|S_ISBLK(mode)	|判断是否是块设备|
|S_ISFIFO(mode)|判断是否是命名管道|
|S_ISSOCK(mode)	|判断是否是套接字|

+ 通常用于判断

```c
if(S_ISDIR(st_mode)){}
```



> 例子1.获得文件大小

```c
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

//获得文件大小
int main()
{
    struct stat buf;
    stat("/etc/passwd",  &buf);
    printf("/etc/passwd file size = %d\n", buf.st_size);
    //如果使用fstat函数实现
    //int fd = open("/etc/passwd", O_RDONLY);//先获得文件描述
    //fstat(fd, &buf);
    return 0;
}
```

> 例子2.判断文件夹的类型及其输出时间


```c
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<time.h>
#include<stdlib.h>


int main()
{
    int fd = open("aaa.txt", O_RDONLY);
    if(-1 == fd)
    {
        perror("open error");
        exit(-1);
    }
    
    struct stat buf;
    int ret = fstat(fd, &buf);
    if(-1 == ret)
    {
        perror("fstat error");
        exit(-1);
    }
    
    if(S_ISREG(buf.st_mode))
    {
        printf("regular file!\n");
    }
    
    if(S_ISDIR(buf.st_mode))
    {
        printf("directory!\n");
    }
    
    if(S_ISLNK(buf.st_mode))
        printf("link file！\n");
        
    printf("the size of the file is : %d\n", buf.st_size);
    
    time_t tt = buf.st_atime;
    struct tm *pt = gmtime(&tt);
    printf("%4d-%02d-%02d    %02d:%02d:%02d\n", (1900+pt->tm_year), (1+pt->tm_mon), pt->tm_mday, (8+pt->tm_hour), pt->tm_min, pt->tm_sec);
    close(fd);
    return 0;
}
```
> 运行结果

```shell
joe@AverageJoe ~/myGit/CS_exe/3.Linux/file $ ./a.out 
regular file!
the size of the file is : 10
2016-03-22    20:17:35

```



###7.文件描述符的复制

> 1.系统调用函数dup和dup2可以实现文件描述符的复制，经常用来重定向进程的stdin(0),stdout(1),stderr(2)。

> 2.dup返回新的文件描述符（没有使用的文件描述符的最小编号）。这个新的描述符是旧文件描述符的拷贝。这意味着两个描述符共享同一个数据结构。

> 3.dup2允许调用者用一个有效描述符(oldfd)和目标描述符(newfd)，函数成功返回时，目标描述符将变成旧描述符的复制品，此时两个文件描述符现在都指向同一个文件，并且是函数第一个参数（也就是oldfd）指向的文件。


> 原型为

```c
#include <unistd.h>   //头文件包含
int dup(int oldfd);
int dup2(int oldfd, int newfd);
```

> 例子1，dup函数使用

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char*argv[])
{
    char buf[32] = {0};
    int fda = open("d.txt", O_RDWR);
    //d.txt的内容为：helloworld
    int fdaa =dup(fda);
    read(fda, buf, 4);
    puts(buf);
    close(fda);
    
    lseek(fdaa, 0, SEEK_CUR);
    read(fdaa, buf, sizeof(buf));
    puts(buf);
    close(fdaa);
    return 0;
    
    //假设d.txt中的内容为：hello world.上面的例子会发现第一次输出的结果是hell。关闭close(fda)的时候，文件实际上还没有真正的关闭，此时文件指针已经向后移动了。执行第二次read命令将o world读出来，最后关闭fdaa。
}
```

> 运行结果


```shell
joe@AverageJoe ~/myGit/CS_exe/3.Linux/file $ ./a.out 
hell
o world

```

> 例子2.重定向，利用dup函数

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>


int main()
{
    int fd = open("a.txt", O_WRONLY|O_CREAT);
    if(-1 == fd)
    {
        perror("open error");
        exit(-1);
    }
    
    printf("\n");//必不可少
    
    close(1);
    
    int fd2 = dup(fd);
    close(fd);
    
    printf("helloworld\n");
    close(fd2);
    return 0;
    
    /*该程序首先打开了一个文件，返回一个文件描述符，因为默认的就打开了0,1,2表示标准输入，标准输出，标准错误输出。而用close(1);则表示关闭标准输出，此时这个文件描述符就空着了。后面又用dup，此时dup(fd);则会复制一个文件描述符到当前未打开的最小描述符，此时这个描述符为1.后面关闭fd自身，然后在用标准输出的时候，发现标准输出重定向到你指定的文件了。那么printf所输出的内容也就直接输出到文件了。*/
}
```

> 例子3.dup2测试

```c
/*dup2(int fdold,int fdnew)也是进行描述符的复制，只不过采用此种复制，新的描述符由用户用参数fdnew显示指定，而不是象dup一样由内核帮你选定（内核选定的是随机的）。对于dup2，如果fdnew已经指向一个已经打开的文件，内核会首先关闭掉fdnew所指向的原来的文件。此时再针对于fdnew文件描述符操作的文件，则采用的是fdold的文件描述符。如果成功dup2的返回值于fdnew相同,否则为-1*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    char buf[32] = {0};
    int fda = open("a.txt", O_RDONLY);
    int fdb = open("aaa.txt", O_RDONLY);
    int fdbb = dup(fdb);
    int fda2 = dup2(fda, fdb);//fda2的进程设置成fdb的
    printf("fda:%d  fdb:%d  fdbb:%d  fda2:%d\n", fda, fdb, fdbb, fda2);
    read(fdb, buf, sizeof(buf) - 1);
    //此时fdb已经不再定位aaa.txt而是a.txt
    printf("result:%s", buf);
    
    close(fda);
    close(fdb);
    close(fdbb);
    close(fda2);
    return 0;
}
```



###8.标准输入输出文件描述符

> 与标准的输入输出流对应，在更底层的实现是用标准输入、标准输出、标准错误文件描述符表示的。它们分别用STDIN_FILENO、STDOUT_FILENO和STDERR_FILENO三个宏表示，值分别是0、1、2三个整型数字。

|表示|宏|值|
|--------------|-------|---|
|标准输入文件描述符  	|	 STDIN_FILENO  |0|
|标准输出文件描述符		| STDOUT_FILENO		| 1|
|标准错误输出文件描述符	| STDERR_FILENO		| 2|


> 例子

```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char szBuf[32],szBuf2[50];
    printf("Input string:");
fflush(stdout);	//要刷新标准输出流，才可以立即在屏幕上显示”Input  string”
//fflush用于linux中的时候，只对fflush(stdout)有效。
    int iRet=read(STDIN_FILENO,szBuf,sizeof(szBuf));
    szBuf[iRet]=0;	//read是以无类型指针方式读的数据，不会自动在缓冲区后加0结束标记。
    sprintf(szBuf2,"The string is:%s",szBuf);
    write(STDOUT_FILENO,szBuf2,strlen(szBuf2));
    return 0;
    //fsync(int fd) 同步缓冲区到磁盘
}
```


###9.I/O多路转接模型

> I/O多路转接模型：在这种模型下，如果请求的I/O操作阻塞，且它不是真正阻塞I/O，而是让其中的一个函数等待，在这期间，I/O还能进行其他操作。如本节要介绍的select()函数，就是属于这种模型。


> select函数原型与说明

```c
#include <sys/select.h>
#include <sys/time.h>
int select(int maxfd, fd_set *readset,fd_set *writeset, fd_set *exceptionset, const struct timeval * timeout);
```
+ 返回:就绪描述字的正数目，0——超时，-1——出错

+ 参数解释

|参数|说明|
|------|-----------------|
|maxfd：|	最大的文件描述符（其值应该为最大的文件描述符字 + 1）|
|readset：	|内核读操作的描述符字集合|
|writeset：|内核写操作的描述符字集合|
|exceptionset：|内核异常操作的描述符字集合|
|timeout：|等待描述符就绪需要多少时间。NULL代表永远等下去，一个固定值代表等待固定时间，0代表根本不等待，检查描述字之后立即返回|


+ 其中readset、writeset、exceptionset都是fd_set集合。该集合的相关操作如下

```c
void FD_ZERO(fd_set *fdset); 		/* 将所有fd清零 */
void FD_SET(int fd, fd_set *fdset); 	/* 增加一个fd */
void FD_CLR(int fd, fd_set *fdset); 	/* 删除一个fd */
int FD_ISSET(int fd, fd_set *fdset); 	/* 判断一个fd是否有设置 */
```

> 一般来说，在使用select函数之前，首先要使用FD_ZERO和FD_SET来初始化文件描述符集，在使用select函数时，可循环使用FD_ISSET测试描述符集，在执行完对相关文件描述符之后，使用FD_CLR来清除描述符集。

+ 另外，select函数中的timeout是一个struct timeval类型的指针，该结构体如下

```c
struct timeval
{
	long tv_sec;		/* second */  		//秒
	long tv_usec; 	/* microsecond */	//微秒
};
```

> 例子

```c
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
```



###10.实现2路阻塞管道通信

+ 管道文件创建命令

```shell
mkfifo
```

+ read_pipe.c

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<strings.h>
#include<string.h>


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("error args\n");
        return -1;
    }
    
    int fd_r;
    fd_r = open(argv[1], O_RDONLY);
    if(-1 == fd_r)
    {
        perror("open");
        return -1;
    }
    
    
    
      int fd_w;
    fd_w = open(argv[2], O_WRONLY);
    if(-1 == fd_w)
    {
        perror("open");
        return -1;
    }
    
    
   // printf("I am");
    char buf[128];
    bzero(buf, sizeof(buf));
    while(1)
    {
        
        //strcpy(buf, "hello");
        read(fd_r, buf, strlen(buf));
        printf("%s\n", buf);
        
        bzero(buf, sizeof(buf));
        //memset(buf, 0, sizeof(buf));
        read(STDIN_FILENO, buf, sizeof(buf));
        write(fd_w, buf, strlen(buf) - 1);
    }
    return 0;
}
```

+ write_pipe.c

```c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<strings.h>
#include<string.h>

//open管道一段为写，一段为读，否则会卡住
//read管道时候，如果对方关闭，read返回0
//wirte管道时候，如果对方关闭，write（进程异常，SIGPIPE）异常


int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        perror("error args\n");
        return -1;
    }
    int fd_w;
    fd_w = open(argv[1], O_WRONLY);
    if(-1 == fd_w)
    {
        perror("open_W");
        return -1;
    }
    
    int fd_r;
    fd_r = open(argv[2], O_RDONLY);
    if(-1 == fd_r)
    {
        perror("open_r");
        return -1;
    }
    
    
    printf("I am here\n");
    char buf[128];
    bzero(buf, sizeof(buf));
    //strcpy(buf, "hello");
    while(memset(buf, 0, sizeof(buf)), (read(STDIN_FILENO,buf, sizeof(buf)) > 0 ))
    {
        
        write(fd_w, buf, strlen(buf) - 1);
        memset(buf, 0, sizeof(buf));
        read(fd_r,buf , sizeof(buf));
        printf("%s\n", buf);
    }
    return 0;
}
```

+ Makefile

```Makefile
write_pipe:write_pipe.c
	gcc write_pipe.c -o write_pipe
	gcc read_pipe.c -o read_pipe
```






