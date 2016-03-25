> Linux IPC 之管道

> benchmark是linux性能测试工具

##一.标准流管道

> 像文件操作有标准io流一样，管道也支持文件流模式。用来创建连接到另一进程的管道，是通过函数popen和pclose。

+ 函数原型：

```c
#include <stdio.h>
FILE* popen(const char* command, const char* open_mode);
int pclose(FILE* fp);
```
> 说明

+ 函数popen()：允许一个程序将另一个程序作为新进程来启动，并可以传递数据给它或者通过它接收数据。command字符串是要运行的程序名。open_mode必须是“r”或“w”。如果open_mode是“r”，被调用程序的输出就可以被调用程序(popen)使用，调用程序利用popen函数返回的FILE*文件流指针，就可以通过常用的stdio库函数（如fread）来读取被调用程序的输出；如果open_mode是“w”，调用程序(popen)就可以用fwrite向被调用程序发送数据，而被调用程序可以在自己的标准输入上读取这些数据。
+ 函数pclose()：用popen启动的进程结束时，我们可以用pclose函数关闭与之关联的文件流。


> Example1：从标准管道流中读取  打印/etc/profile的内容
```c
#include <stdio.h>
int main()
{
	FILE* fp = popen("cat /etc/profile", "r");
    char buf[512] = {0};
    while(fgets(buf, sizeof(buf), fp))
    {
   			puts(buf);
    }
    pclose(fp);
    return 0;
}
```
> Example2：写到标准管道流   统计buf单词数(被调用程序必须阻塞等待标准输入)

```c
#include<stdio.h>
int main()
{
	char buf[]={"aaa  bbb  ccc  ddd  eee  fff  ggg  hhh"};
	FILE *fp = popen("wc -w", "w");
	fwrite(buf, sizeof(buf), 1, fp);
	pclose(fp);
	return 0;
}
```


> Example3:

```c
//add.c
#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    printf("the sum is %d\n", a+b);
    return 0;
}
```

```c
//popen_w.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args\n");
        return -1;
    }
    
    FILE *fd;
    fd = popen(argv[1], "w");
    if(NULL == fd)
    {
        perror("popen");
        return -1;
    }
    char buf[128] = "3 4";
    int ret;
    ret = fwrite(buf, sizeof(char), strlen(buf), fd);
    if(ret < 0)
    {
        perror("frite");
        return -1;
    }
    pclose(fd);
    return 0;
}
```

> 运行结果
```sh
joe@AverageJoe ~/localWork/LInux/0325/IPC $ gcc popen.c 
joe@AverageJoe ~/localWork/LInux/0325/IPC $ ./a.out ./1
ajksdhkf

joe@AverageJoe ~/localWork/LInux/0325/IPC $ 

```


##二.无名管道（管道通信）,pipe

> 管道是linux进程间通信的一种方式，如命令ps -ef | grep ntp
无名管道的特点：

+ 1.只能在亲缘关系进程间通信（父子或兄弟）
+ 2.半双工（固定的读端和固定的写端）
+ 3.他是特殊的文件，可以用read、write等，只能在内存中

+ 管道函数原型：

```c
#include <unistd.h> 
int pipe(int fds[2]);
```
> 说明

+ 管道在程序中用一对文件描述符表示，其中一个文件描述符有可读属性，一个有可写的属性。fds[0]是读，fds[1]是写。
+ 函数pipe用于创建一个无名管道，如果成功，fds[0]存放可读的文件描述符，fds[1]存放可写文件描述符,并且函数返回0，否则返回-1。
+ 通过调用pipe获取这对打开的文件描述符后，一个进程就可以从fds[0]中读数据，而另一个进程就可以往fds[1]中写数据。当然两进程间必须有继承关系，才能继承这对打开的文件描述符。
+ 管道不象真正的物理文件，不是持久的，即两进程终止后，管道也自动消失了。

> Example1.创建一个管道，然后进行写与读

```c
//无名管道

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
    int fds[2];
    pipe(fds);//打开管道
    if(!fork())//子进程
    {
        close(fds[0]);//先关闭读端
        write(fds[1], "hello", 5);
        close(fds[1]);//写完之后关闭写端
        exit(0);
    }else{//父进程
        close(fds[1]);//先关闭写端
        char buf[10] = {0};
        read(fds[0], buf, sizeof(buf));
        printf("i am a parent. the buf is %s\n", buf);
        close(fds[0]);//读完之后关闭读端
        return 0;
    }
}

//benchmark最大的读写的百M
```

```shell
joe@AverageJoe ~/localWork/LInux/0325/pipe $ gcc pipe.c
joe@AverageJoe ~/localWork/LInux/0325/pipe $ ./a.out 
i am a parent. the buf is hello
joe@AverageJoe ~/localWork/LInux/0325/pipe $ 
```


> Example2.创建父子进程，创建无名管道，父写子读

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    int fds[2] = {0};
    pipe(fds);
	char szBuf[32] = {'\0'};
	if(fork() == 0){	//表示子进程
		close(fds[1]);	//子进程关闭写
        sleep(2);		//确保父进程有时间关闭读，并且往管道中写内容
		if(read(fds[0], szBuf, sizeof(szBuf)) > 0)
		    puts(buf);
		close(fds[0]);	//子关闭读
		exit(0);
	}else{  			//表示父进程
		close(fds[0]);	//父关闭读
		write(fds[1],  "hello", 6);
		waitpid(-1, NULL, 0);		//等子关闭读
		//write(fds[1], "world",6);	//此时将会出现“断开的管道”因为子的读已经关闭了
		close(fds[1]);	//父关闭写
		exit(0);
	}
	return 0;
}
```

##三.命名管道(FIFO)

> **无名管道只能在亲缘关系的进程间通信**大大限制了管道的使用，有名管道突破了这个限制，通过指定路径名的范式实现不相关进程间的通信

####3.1.创建、删除FIFO文件

> 创建FIFO文件与创建普通文件很类似，只是创建后的文件用于FIFO。


> 1.用函数创建和删除FIFO文件

> 创建FIFO文件的函数原型：

```c
#include <sys/types.h>
#include <sys/stat.h>
int mkfifo(const char *pathname, mode_t mode);
```
> 说明

+ 参数pathname为要创建的FIFO文件的全路径名；

+ 参数mode为文件访问权限

+ 如果创建成功，则返回0，否则-1。

```c
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("error args");
        return -1;
    }
    int ret;
    ret = mkfifo(argv[1], 0666);
    if(ret == -1)
    {
        perror("mkfio failed");
        return -1;
    }
    return 0;
}
```

+ 2.删除FIFO文件的函数原型为

```c
#include <unistd.h>
int unlink(const char *pathname);
```
> 例子

```c
#include <unistd.h>
main()
{
    unlink("pp");
}
```

> 2.打开、关闭FIFO文件

+ 对FIFO类型的文件的打开/关闭跟普通文件一样，都是使用open和close函数。如果打开时使用O_WRONLY选项，则打开FIFO的写入端，如果使用O_RDONLY选项，则打开FIFO的读取端，写入端和读取端都可以被几个进程同时打开。
+ 如果以读取方式打开FIFO，并且还没有其它进程以写入方式打开FIFO，open函数将被阻塞；同样，如果以写入方式打开FIFO，并且还没其它进程以读取方式FIFO，open函数也将被阻塞。
+ 与PIPE相同，关闭FIFO时，如果先关读取端，将导致继续往FIFO中写数据的进程接收SIGPIPE的信号。

> 3.读写FIFO

```c
//write.c
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>


int main()
{
    int fd = open("Myfifo.pip", O_WRONLY);
    write(fd, "hello", 6);
    close(fd);
    return 0;
}
```

```c
//read.c
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    char buf[128] = {0};
    int fd = open("Myfifo.pip", O_RDONLY);
    if(read(fd, buf, sizeof(buf)) > 0)
        puts(buf);
    close(fd);
    return 0;
}
```

> 运行步骤

```shell
mkfifo Myfifo.pip

gcc -o read read.c

gcc -o write write.c

#开2个终端，分别运行
```


##四.管道示例：基于管道的客户端服务器程序。

> 程序说明：

+ 1．服务器端：

> 维护服务器管道，接受来自客户端的请求并处理（本程序为接受客户端发来的字符串，将小写字母转换为大写字母。）然后通过每个客户端维护的管道发给客户端。

+ 2．客户端

> 向服务端管道发送数据，然后从自己的客户端管道中接受服务器返回的数据。

```c
//ServerBaseFIFO_client.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>


typedef struct tagmag
{
    int client_pid;
    char my_data[512];
}MSG;


int main()
{
    int server_fifo_fd, client_fifo_fd;
    char client_fifo[256] = {0};
    sprintf(client_fifo, "CLIENT_FIFO_%d", getpid());
    MSG my_msg;
    memset(&my_msg, 0, sizeof(MSG));
    my_msg.client_pid = getpid();
    server_fifo_fd = open("./SERVER_FIFO_NAME", O_WRONLY);
    mkfifo(client_fifo, 0777);
    while(1)
    {
        int n = read(STDIN_FILENO, my_msg.my_data, 512);
        my_msg.my_data[n] = '\0';
        write(server_fifo_fd, &my_msg, sizeof(MSG));
        client_fifo_fd = open(client_fifo, O_RDONLY);
        n =read(client_fifo_fd, &my_msg, sizeof(MSG));
        my_msg.my_data[n] = 0;
        write(STDOUT_FILENO, my_msg.my_data, strlen(my_msg.my_data));
        close(client_fifo_fd);
   }
   unlink(client_fifo);
}
```

```c
//ServerBaseFIFO_server.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>

typedef struct tagmag
{
    int client_pid;
    char my_data[512];
}MSG;

int main()
{
    int server_fifo_fd, client_fifo_fd;
    char client_fifo[256];
    MSG my_msg;
    char *pstr;
    memset(&my_msg, 0, sizeof(MSG));
    mkfifo("SERVER_FIFO_NAME", 0777);
    server_fifo_fd = open("./SERVER_FIFO_NAME", O_RDONLY);
    if(server_fifo_fd == -1)
    {
        perror("server_fifo_fd");
        exit(-1);
    }
    
    int ret;
    while((ret = read(server_fifo_fd, &my_msg, sizeof(MSG))>0))
    {
        pstr = my_msg.my_data;
        printf("%s\n", my_msg.my_data);
        while(*pstr != '\0')
        {
            *pstr = toupper(*pstr);
            pstr++;
        }
        memset(client_fifo, 0, 256);
        sprintf(client_fifo, "CLIENT_FIFO_%d",my_msg.client_pid);
        client_fifo_fd = open(client_fifo, O_WRONLY);
        if(client_fifo_fd == -1)
        {
            perror("client_fifo_fd");
            exit(-1);
        }
    }
    write(client_fifo_fd, &my_msg, sizeof(MSG));
    printf("%s\n", my_msg.my_data);
    printf("OVER!\n");
    close(client_fifo_fd);
    return 0;
}   
    
```

