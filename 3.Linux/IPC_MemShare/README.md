Linux IPC之共享内存
=========================

> 原理及实现：system V IPC机制下的共享内存本质是一段特殊的内存区域，进程间需要共享的数据被放在该共享内存区域中，所有需要访问该共享区域的进程都要把该共享区域映射到本进程的地址空间中去。这样一个使用共享内存的进程可以将信息写入该空间，而另一个使用共享内存的进程又可以通过简单的内存读操作获取刚才写入的信息，使得两个不同进程之间进行了一次信息交换，从而实现进程间的通信。共享内存允许一个或多个进程通过同时出现在它们的虚拟地址空间的内存进行通信，而这块虚拟内存的页面被每个共享进程的页表条目所引用，同时并不需要在所有进程的虚拟内存都有相同的地址。进程对象对于共享内存的访问通过key（键）来控制，同时通过key进行访问权限的检查

```shell
ipcs #查看共享内存

ipcrm -m shmid #删除共享内存
```

##一.函数原型定义如下：

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
key_t ftok(const char *pathname, int proj_id);//获得key值
int shmget(key_t key, int size, int shmflg);//创建或打开一共享内存段
void *shmat(int shmid, const void *shmaddr, int shmflg);
int shmdt(const void *shmaddr);
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```


##二.说明


####1.函数ftok

```c
key_t ftok(const char *pathname, int proj_id);

```

+ 用于创建一个关键字，可以用该关键字关联一个共享内存段。

+ 参数pathname为一个全路径文件名，并且该文件必须可访问。

+ 参数proj_id通常传入一非0字符

+ 通过pathname和proj_id组合可以创建唯一的key

+ 如果调用成功，返回一关键字，否则返回-1

####2.函数shmget

```c
int shmget(key_t key, int size, int shmflg);
```
+ 用于创建或打开一共享内存段，该内存段由函数的第一个参数唯一创建。函数成功，则返回一个唯一的共享内存标识号（相当于进程号，唯一的标识着共享内存），失败返回-1。

+ 参数key是一个与共享内存段相关联关键字，如果事先已经存在一个与指定关键字关联的共享内存段，则直接返回该内存段的标识，表示打开，如果不存在，则创建一个新的共享内存段。key的值既可以用ftok函数产生，也可以是IPC_PRIVATE（用于创建一个只属于创建进程的共享内存，主要用于父子通信）,表示总是创建新的共享内存段；

+ 参数size指定共享内存段的大小，以字节为单位；

+ 参数shmflg是一掩码合成值，可以是访问权限值与(IPC_CREAT或IPC_EXCL)的合成。IPC_CREAT表示如果不存在该内存段，则创建它。IPC_EXCL表示如果该内存段存在，则函数返回失败结果(-1)。如果调用成功，返回内存段标识，否则返回-1


> 例子

```c
//shmget.c
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args");
        exit(-1);
    }
    key_t key;
    key = ftok(argv[1],1);//产生key值
    int shmid;//声明共享内存的id
    shmid = shmget(key, 1<<10, IPC_CREAT|0600);//创建共享内存并且获得共享内存id
    if(-1 == shmid)
    {
        perror("shmget");
        exit(-1);
    }
    return 0;
}
//共享内存需要显式地删除
```

> 运行

```shell
touch file
gcc shmget.c -o 1
./a file
```

####3.函数shmat
```c
void *shmat(int shmid, const void *shmaddr, int shmflg);
```
+ 将共享内存段映射到进程空间的某一地址。

+ 参数shmid是共享内存段的标识  通常应该是shmget的成功返回值

+ 参数shmaddr指定的是共享内存连接到当前进程中的地址位置。通常是NULL，表示让系统来选择共享内存出现的地址。

+ 参数shmflg是一组位标识，通常为0即可。**意思是在操作的时候不允许其他程序操作该位置**

+ 如果调用成功，返回映射后的进程空间的首地址，否则返回(char *)-1。

> 例子1：实现一个进程读和一个进程写进行共享内存通信

```c
//shmat.c
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>//sleep函数
#include<string.h>


typedef struct {
    int lock;
    int noread;
    char buf[1024];
}chat, *pchat;


void lock(int* p)
{
    while(1)
    {
        if(*p == 0)
        {
            *p = 1;
            break;
        }
    }
}

void unlock(int *p)
{
    *p = 0;
}


int main(int argc, char* argv[])
{
    int shmid;//声明共享内存的id
    shmid = shmget((key_t)1235, 1<<10, IPC_CREAT|0600);//创建共享内存并且获得共享内存id,有iIPC_EXCL在重新创建相同的共享内存的时候会提示创建失败
    if(-1 == shmid)
    {
        perror("shmget");
        exit(-1);
    }
    pchat p;
    p = (pchat)shmat(shmid, NULL, 0);//链接共享内存
    if((pchat)-1 == p)
    {
        perror("shmat");
        return -1;
    }
    //sleep(15);//链接15秒
    //p[0] = 'H';//写入共享内存
    char buf[1024];
    memset(p, 0, sizeof(chat));//初始化为0
    memset(buf, 0, sizeof(buf));
    while(memset(buf, 0, sizeof(buf)), scanf("%s", buf) != EOF)
    {
        lock(&p->lock);//加锁
        strcpy(p->buf,buf);
        p->noread = 1;
        unlock(&p->lock);
    }
    return 0;
}
//共享内存需要显式地删除
```

```c
//shmat_r.c
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>//sleep函数
#include<string.h>

typedef struct {
    int lock;
    int noread;
    char buf[1024];
}chat, *pchat;



void lock(int* p)
{
    while(1)
    {
        if(*p == 0)
        {
            *p = 1;
            break;
        }
    }
}

void unlock(int *p)
{
    *p = 0;
}



int main(int argc, char* argv[])
{
    int shmid;//声明共享内存的id
    shmid = shmget((key_t)1235, 1<<10, IPC_CREAT|0600);//创建共享内存并且获得共享内存id,有iIPC_EXCL在重新创建相同的共享内存的时候会提示创建失败
    if(-1 == shmid)
    {
        perror("shmget");
        exit(-1);
    }
    pchat p;
    p = (pchat)shmat(shmid, NULL, 0);//链接共享内存
    if((pchat)-1 == p)
    {
        perror("shmat");
        return -1;
    }
    while(1)
    {
        lock(&p->lock);
        if(p->noread == 1)
        {
            printf("%s\n", p->buf);
            p->noread = 0;
            memset(p->buf, 0, sizeof(p->buf));
        }
        unlock(&p->lock);
        usleep(5);
    }
    //sleep(15);//链接15秒
    //printf("The p[0] is %c\n", p[0]);//从共享内存读出
    return 0;
}
```

> 例子2：实现一个进程读和写与另一个进程读和写进行共享内存通信

+ shmat_w.c

```c
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>//sleep函数
#include<string.h>
#include<sys/select.h>


typedef struct {
    int lock;
    int noread;
    char buf[1024];
}chat, *pchat;


void lock(int* p)
{
    while(1)
    {
        if(*p == 0)
        {
            *p = 1;
            break;
        }
    }
}

void unlock(int *p)
{
    *p = 0;
}


int main(int argc, char* argv[])
{
    int shmid;//声明共享内存的id
    shmid = shmget((key_t)1235, 1<<10, IPC_CREAT|0600);//创建共享内存并且获得共享内存id,有iIPC_EXCL在重新创建相同的共享内存的时候会提示创建失败
    if(-1 == shmid)
    {
        perror("shmget");
        exit(-1);
    }
    pchat p;
    p = (pchat)shmat(shmid, NULL, 0);//链接共享内存
    if((pchat)-1 == p)
    {
        perror("shmat");
        return -1;
    }
    //sleep(15);//链接15秒
    //p[0] = 'H';//写入共享内存
    char buf[1024];
    memset(p, 0, sizeof(chat));//初始化为0
    memset(buf, 0, sizeof(buf));
    fd_set rdset;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    int ret;
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(0, &rdset);
        ret = select(1, &rdset, NULL, NULL, &tv);
        if(ret > 0)
        {
            memset(buf, 0, sizeof(buf));
            read(0, buf, sizeof(buf));//读进来
            lock(&p->lock);//加锁
            strncpy(p->buf,buf, strlen(buf) - 1);//防止读的时候换行
            p->noread = 1;
            unlock(&p->lock);
        }
        lock(&p->lock);
        if(p->noread == 2)
        {
            printf("%s\n", p->buf);
            p->noread = 0;
            memset(p->buf, 0, sizeof(p->buf));
        }
        unlock(&p->lock);
        usleep(5);
    }
    return 0;
}
//共享内存需要显式地删除
```

+ shmat_r.c

```c
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>//sleep函数
#include<string.h>
#include<sys/select.h>



typedef struct {
    int lock;
    int noread;
    char buf[1024];
}chat, *pchat;



void lock(int* p)
{
    while(1)
    {
        if(*p == 0)
        {
            *p = 1;
            break;
        }
    }
}

void unlock(int *p)
{
    *p = 0;
}



int main(int argc, char* argv[])
{
    int shmid;//声明共享内存的id
    shmid = shmget((key_t)1235, 1<<10, IPC_CREAT|0600);//创建共享内存并且获得共享内存id,有iIPC_EXCL在重新创建相同的共享内存的时候会提示创建失败
    if(-1 == shmid)
    {
        perror("shmget");
        exit(-1);
    }
    pchat p;
    p = (pchat)shmat(shmid, NULL, 0);//链接共享内存
    if((pchat)-1 == p)
    {
        perror("shmat");
        return -1;
    }
    fd_set rdset;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100;
    int ret;
    char buf[1024];
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(0, &rdset);
        ret = select(1, &rdset, NULL, NULL, &tv);
        if(ret > 0)
        {
            memset(buf, 0, sizeof(buf));
            read(0, buf, sizeof(buf));//读进来
            lock(&p->lock);//加锁
            strncpy(p->buf,buf, strlen(buf) - 1);
            p->noread = 2;
            unlock(&p->lock);
        }
        lock(&p->lock);
        if(p->noread == 1)
        {
            printf("%s\n", p->buf);
            p->noread = 0;
            memset(p->buf, 0, sizeof(p->buf));
        }
        unlock(&p->lock);
        usleep(5);
    }
    return 0;
}
```

####4.函数shmdt

```c
int shmdt(const void *shmaddr);
```

+ 用于将共享内存段与进程空间分离。

+ 参数shmaddr通常为shmat的成功返回值。

+ 函数成功返回0，失败时返回-1.注意，将共享内存分离并没删除它，只是使得该共享内存对当前进程不在可用。

####5.函数shmctl

```c
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```

+ 是共享内存的控制函数，可以用来删除共享内存段。

+ 参数shmid是共享内存段标识 通常应该是shmget的成功返回值

+ 参数cmd是对共享内存段的操作方式，可选为IPC_STAT, IPC_SET, IPC_RMID， 通常为IPC_RMID，表示删除共享内存段。

+ 参数buf是表示共享内存段的信息结构体数据，通常为NULL。

+ 例如shmctl(kshareMem,IPC_RMID,NULL)表示删除调共享内存kHareMem


##三.例子

> 例子一.有亲缘关系

```c
#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#define  PERM  S_IRUSR | S_IWUSR  //表示用户可读可写 即0600

int main(int argc,char **argv) 
{
	/*在两个有亲属关系进程间通信,KEY采用IPC_PRIVATE由系统自选*/
	int shmid = shmget(IPC_PRIVATE, 1024, PERM); //只有IPC_PRIVATE情况可以不设置IPC_CREAT
	if(shmid == -1) /* 创建byte 的共享内存*/
	{
		fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno));
		exit(1);
	}
	if(fork() > 0)  /* 父进程代码*/
	{
		char *p_addr = (char*)shmat(shmid, NULL, 0);  //获得该段共享内存的首地址
		memset(p_addr, '\0', 1024);  //初始化为0
		strncpy(p_addr, "share memory", 1024);  //存入（写入）内容
		printf("parent %d  Write buffer: %s\n", getpid(), p_addr);
		sleep(2);
		wait(NULL);	//防止僵尸进程
		shmctl(shmid, IPC_RMID, 0);/*删除共享内存,用ipcs -m看共享内存*/
		exit(0); 
	}

	else /* 子进程代码*/
	{
		sleep(5);   //让父有足够的时间写
		char *c_addr = (char*)shmat(shmid, NULL, 0);  //取出（读出）内容
		printf("Client pid=%d,shmid =%d Read buffer: %s\n",getpid(),shmid,c_addr);
		exit(0);
	}
}
```

> 例子二.非亲进程间通信的实现步骤如下

+ 写内存端


```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>  //头文件包含
#include <sys/types.h>
main()
{
    key_t key = ftok("b.dat",1);					//1. 写入端先用ftok函数获得key
    if(key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int shmid = shmget(key,4096,IPC_CREAT); 	//2. 写入端用shmget函数创建一共享内存段
    if(shmid == -1)
    {
        perror("shmget");
        exit(-1);
    }
    char *pMap = (char *)shmat(shmid, NULL, 0);	//3. 获得共享内存段的首地址
    memset(pMap, 0, 4096);
    memcpy(pMap, "hello world", 4096);			//4. 往共享内存段中写入内容
    if(shmdt(pMap) == -1)						//5. 关闭共享内存段
    {
        perror("shmdt");
        exit(-1);
    }
}

```

+ 读内存端

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
main()
{
    key_t key = ftok("b.dat",1);					//1. 读入端用ftok函数获得key
    if(key == -1)
    {
        perror("ftok");
        exit(-1);
    }
    int shmid = shmget(key,4096,0600|IPC_CREAT);		//2. 读入端用shmget函数打开共享内存段
    if(shmid == -1)
    {
        perror("shmget");
        exit(-1);
    }
    char *pMap = (char *)shmat(shmid, NULL, 0); 	//3. 获得共享内存段的首地址
    printf("receive the data:%s\n",pMap);			//4. 读取共享内存段中的内容
    if(shmctl(shmid, IPC_RMID, 0) == -1)			//5. 删除共享内存段
    {
        perror("shmctl");
        exit(-1);
    }
}
```

> 例子三.通过共享内存实现两个程序间的对话

+ shmwr.c

```c
//shmwr.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
struct text
{
        int useful;
        char buf[1024];
};
int main()
{
        int shmid = shmget((key_t)5080 , sizeof(struct text),0600|IPC_CREAT);
        printf("%d \n" ,shmid);
        struct text* ptext = (struct text *)shmat(shmid , NULL , 0);
//      ptext->useful = 0 ;
        while(1)
        {
                if(ptext -> useful == 0)
				{
                        int iret = read(STDIN_FILENO , ptext->buf , 1024);
                        ptext->useful = 1;
                        if(strncmp("end" , ptext->buf,3)==0)
                        {
                                break ;
                        }
                        //ptext ->useful = 0 ;
                }
                sleep(1);
        }
                shmdt((void *)ptext);
                return 0 ;
}
```

+ shmrd.c

```c
//shmrd.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
struct text
{
        int useful;
        char buf[1024];
};
int main()
{
        int shmid = shmget((key_t)5080 , sizeof(struct text),0600|IPC_CREAT);
        struct text* ptext = (struct text *)shmat(shmid , NULL , 0);
        ptext->useful = 0 ;
        while(1)
        {
                if(ptext -> useful == 1)
                {
                        write(STDOUT_FILENO,ptext -> buf , strlen(ptext -> buf));
                        ptext ->useful = 0 ;
                        if(strncmp("end" , ptext->buf,3)==0)
                        {
                                break ;
                        }
                }
                sleep(1);
        }
                shmdt((void *)ptext);
                shmctl(shmid , IPC_RMID,0);
                return 0 ;
}
```

> shmid_ds结构体

```c
struct shmid_ds {
               struct ipc_perm shm_perm;    /* Ownership and permissions */
               size_t          shm_segsz;   /* Size of segment (bytes) */
               time_t          shm_atime;   /* Last attach time */
               time_t          shm_dtime;   /* Last detach time */
               time_t          shm_ctime;   /* Last change time */
               pid_t           shm_cpid;    /* PID of creator */
               pid_t           shm_lpid;    /* PID of last shmat(2)/shmdt(2) */
               shmatt_t        shm_nattch;  /* No. of current attaches */
               ...
           };
struct ipc_perm {
               key_t          __key;    /* Key supplied to shmget(2) */
               uid_t          uid;      /* Effective UID of owner */
               gid_t          gid;      /* Effective GID of owner */
               uid_t          cuid;     /* Effective UID of creator */
               gid_t          cgid;     /* Effective GID of creator */
               unsigned short mode;     /* Permissions + SHM_DEST and
                                           SHM_LOCKED flags */
               unsigned short __seq;    /* Sequence number */
           };
```



> ipc_perm的mode详解表

|操作者	|读|	写（更改 更新）	|操作者	|读	|写（更改 更新）|
|-------|----|----||------|----|----|
|用户	|0400	|0200	|其他|	0004	|0002|
|组	|0040|	0020|		||||	


##四.使用共享内存的优缺点
+ 1、优点：我们可以看到使用共享内存进行进程间的通信真的是非常方便，而且函数的接口也简单，数据的共享还使进程间的数据不用传送，而是直接访问内存，也加快了程序的效率。同时，它也不像匿名管道那样要求通信的进程有一定的父子关系。

+ 2、缺点：共享内存没有提供同步的机制，这使得我们在使用共享内存进行进程间通信时，往往要借助其他的手段来进行进程间的同步工作。

