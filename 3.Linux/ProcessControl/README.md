> Linux进程控制



#一.Linux进程概述



###1.0.程序与进程关系

+ 程序运行时创建一个状态并且存储在内存中，程序运行的状态称作进程

+ 进程是一个程序一次运行的过程

+ 进程有四种状态：创建，调度，消亡，进程是linux的基本调度单位

+ 内核态：内核线程，任务（task）

+ PCB（process control block），进程信息结构体，包含了进程的描述，控制，资源信息，它是进程的一个静态描述

+ 内核的调度器（内核线程）去负责所有的进程分配cpu执行时间，成为时间片，它轮流在每个进程分的时间片用完后从进程那抢回控制权，**称为时间片轮转**

+ 优先级不同的进程得到的时间片不同

**以上为：普通调度策略，也叫OTHER调度策略**



> 实时调度策略 RR FIFO，一个系统只能开一个



```sh

ps -elf

#查看进程信息

```



###1.1.进程标识

+ 每个进程有唯一的一个整型ID，叫做**PID：进程标识号**

+ 进程 除了自身id外，还有**父进程：PPID**

+ ID为0的进程是调度进程，叫做**交换进程**，是内核的一部分，不执行任何磁盘上的程序，也称为**系统进程**

+ 所有进程的**祖先进程**是同一个进程，是**init进程**，ID号为1

+ init进程是内核自举过程结束时由内核调用的进程，init负责**引导系统，启动守护(后台)进程，运行必要的程序**

+ 进程的pid和ppid可以分别通过函数**getpid()，getppid**获得



> 例子



```c



#include<stdio.h>

#include<unistd.h>



int main()

{

    pid_t pid,ppid;

    pid = getpid();//得到的是当前程序的进程号

    ppid = getppid();

    printf("pid:%d  ppid:%d\n", pid, ppid);

    return 0;

}

```

```sh

unlink

#删除文件函数和命令

```

###1.2.进程的用户ID和组ID（进程的运行身份）

+ 真实用户id和真实组ID可以通过函数getuid()，getgid()获取

+ 有效用户id和有效组ID可以通过函数geteuid()，getegid()获取

+ passwd命令修改的命令是存储在 /etc/shadow，普通用户也可以修改自身密码，这与euid有关，passwd命令在/usr/bin/passwd中，---s---------，即为权限提升，-----t，权限粘滞位

```sh

lasttr

#边缘权限

```



###1.3.进程的状态

> 根据进程的声明周期可以划分为三种状态：



+ 执行态：该进程正在运行，即进程正在占用CPU。

+ 就绪态：进程已经具备执行的一切条件，正在等待分配CPU的处理时间片。

+ 等待态：进程不能使用CPU，若等待事件发生（等待的资源分配到）则可将其唤醒。






###1.4.Linux下的进程结构



> Linux系统是一个多进程的系统，它的进程之间具有并行性、互不干扰等特点。也就是说，进程之间是分离的任务，拥有各自的权利和责任。其中，每个进程都运行在各自独立的虚拟地址空间，因此，即使一个进程发生了异常，它也不会影响到系统的其他进程。



> Linux中的进程包含3个段，分别为“数据段”、“代码段”和“堆栈段”。



+ “数据段”放全局变量、常数以及动态数据分配的数据空间。数据段分成普通数据段（包括可读可写/只读数据段，存放静态初始化的全局变量或常量）、BSS数据段（存放未初始化的全局变量）以及堆（存放动态分配的数据）。

+ “代码段”存放的是程序代码的数据。

+ “堆栈段”存放的是子程序的返回地址、子程序的参数以及程序的局部变量等。 






###1.5.Linux下的进程管理

> 启动进程 ：手动启动，调度启动





> 命令说明



```sh

ps -elf #uid,pid,优先级

#可以看到进程的四种状态：S睡眠，T暂停，R运行，Z僵尸

ps -aux #查看所有的进程

ps -aux | grep 'aa' #查找指定进程

ps -ef #可以显示父子进程的关系



top #显示前20条的进程，动态的改变



kill#杀进程





crontab #/etc/crontab

kill -l #显示

kill -9 id #杀死一个进程

kill -19 id #睡眠一个进程，显示为T状态，即停止状态

kill -18 id#运行一个睡眠进程

pkill a #可以杀死进程名字为a的进程



jobs  #显示后台运行进程

./a.out & #后台运行

fg 1&2 #将任务带到前台

bg id #将前台程序转为后台

```



#二.进程的创建



###2.1.system函数



> system函数通过调用shell程序/bin/sh –c来执行string所指定的命令，该函数在内部是通过调用execve(“/bin/sh”,..)函数来实现的。通过system创建子进程后，原进程和子进程各自运行，相互间关联较少。如果system调用成功，将返回0





> 此外，system函数后面的参数还可以是一个可执行程序，例如:system(“/home/joe/1”);如果想要执行system后面进程的时候，不至于对当前进程进行阻塞，可以利用&将/home/joe/1调到后台运行。





```c

#include <stdio.h>

#include <stdlib.h>

int main()

{

	system("ls -l "); //system(“clear”);表示清屏

	return 0;

}

```

###2.2.fork函数

+ 原型



```c

#include <unistd.h>

		pid_t fork(void);

```



> 在linux中fork函数是非常重要的函数，它从已存在进程中创建一个新进程。新进程为子进程，而原进程为父进程。它和其他函数的区别在于：它执行一次返回**两个值**。其中父进程的返回值是子进程的进程号，而子进程的返回值为0.若出错则返回-1.因此可以通过返回值来判断是父进程还是子进程。



> fork函数创建子进程的过程为：使用fork函数得到的子进程是父进程的一个复制品，它从父进程继承了进程的地址空间，包括**进程上下文、进程堆栈、内存信息、打开的文件描述符、信号控制设定、进程优先级、进程组号、当前工作目录、根目录、资源限制、控制终端，而子进程所独有的只有它的进程号、资源使用和计时器**等。通过这种复制方式创建出子进程后，原有进程和子进程都从函数fork返回，各自继续往下运行，但是原进程的fork返回值与子进程的fork返回值不同，在原进程中，fork返回子进程的pid,而在子进程中，fork返回0,如果fork返回负值，表示创建子进程失败。（vfork函数）





```c

pid = fork();

if(pid == 0)

{

    //子进程的代码，因为fork给子进程返回0

}else{

//父进程代码

}

```



> 例子



```c

#include <stdlib.h>

#include <unistd.h>

#include<stdio.h>

int main()

{

    printf("Parent process id:%d\n",getpid());

    pid_t iRet = fork();

    if(iRet < 0){//出错

        printf("Create child process fail!\n");

    }else if(iRet == 0){//表示子进程

        printf("child process id:%d ppid:%d\n",getpid(),getppid());

        exit(0);//进程退出

    }else{//表示父进程

        printf("parent process success,child id:%d\n",iRet);

        exit(0);//进程退出

    }

    return 0;

}

//这里if和else里面的语句都得到执行了，和我们以前的if…else结构不同，此时相当于有两份main函数代码的拷贝，其中一份做的操作是if(iRet == 0)的情况；另外一份做的操作是else(父)的情况。所以可以输出2句话。**提问：如何创建兄弟进程和爷孙进程？**

```



###2.3.exec函数族

> exec函数族的工作过程与fork完全不同，fork是在复制一份原进程，而exec函数是用exec的第一个参数指定的程序覆盖现有进程空间（也就是说执行exec族函数之后，它后面的所有代码不在执行）



+ 原型

```c

int execl(const char *path, const char *arg, ...)

```

> 参数说明



+ path是包括执行文件名的全路径名	   

	+ arg是可执行文件的命令行参数，多个用，分割注意最后一个参数必须为NULL。



> 例子：有个加法程序，从命令行接受两个数，输出其和 。



```c

//main.c

#include<stdio.h>

#include<string.h>

#include<unistd.h>



int main()

{

    execl("/add", "add", "3", "4", NULL);

    return 0;

}

//add.c


#include<stdio.h>

#include<string.h>



int main(int argc, char *argv[])

{

    int a = atoi(argv[1]);

    int b = atoi(argv[2]);

    printf("%d + %d = %d", a, b, a + b);

    return 0;

}

```



> 参数说明



+ command为可执行文件的全路径和执行参数；

+ type可选参数为”r”或”w”,如果为”w”,则popen返回的文件流做为新进程的标准输入流，即stdin，如果为”r”,则popen返回的文件流做为新进程的标准输出流。

+ 如果type是“r”，（即command命令执行的输出结果作为当前进程的输入结果）。被调用程序的输出就可以被调用程序使用，调用程序利用popen函数返回的FILE*文件流指针，就可以通过常用的stdio库函数（如fread）来读取被调用程序的输出；如果tpye是“w”，（即当前进程的输出结果作为command命令的输入结果）。调用程序就可以用fwrite向被调用程序发送数据，而被调用程序可以在自己的标准输入上读取这些数据。

+ pclose等待新进程的结束，而不是杀新进程。



###2.4.popen函数

>popen函数类似于system函数，与system的不同之处在于它使用管道工作。



+ 原型



```c

#include <stdio.h>

  	FILE *popen(const char *command, const char *type);

  	int pclose(FILE *stream);



```



> 例子



```c

#include<unistd.h>

#include<stdlib.h>

#include<stdio.h>

#include<string.h>





int main()

{

    FILE *read_fp;

    char buffer[BUFSIZ + 1];

    int chars_read;

    

    memset(buffer, '\0', sizeof(buffer));

    read_fp = popen("ps -ax", "r");

    if(read_fp != NULL)

    {

        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);

        while(chars_read > 0)

        {

            buffer[chars_read - 1] = '\0';

            printf("Reading : \n %s\n", buffer);

            chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);

        }

        pclose(read_fp);

        exit(EXIT_SUCCESS);

    }

    exit(EXIT_FAILURE);

}

```



#三.进程的控制与终止



###3.1.进程的控制



> 用fork函数启动一个子进程时，子进程就有了它自己的生命并将独立运行。



> 如果父进程先于子进程退出，则子进程成为孤儿进程，此时将自动被PID为1的进程（即init）接管。孤儿进程退出后，它的清理工作有祖先进程init自动处理。但在init进程清理子进程之前，它一直消耗系统的资源，所以要尽量避免。



```c

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>



void main()

{

    pid_t pid = fork();

    if(pid == 0)

    {

        while(1);//子进程继续

    }else{

        exit(1);//退出父进程

    }

}

```





> 如果子进程先退出，系统不会自动清理掉子进程的环境，而必须由父进程调用wait或waitpid函数来完成清理工作，如果父进程不做清理工作，则已经退出的子进程将成为僵尸进程(defunct),在系统中如果存在的僵尸（zombie）进程过多，将会影响系统的性能，所以必须对僵尸进程进行处理。



+ 原型



```c

#include <sys/types.h>

        #include <sys/wait.h>

        pid_t wait(int *status);

        pid_t waitpid(pid_t pid, int *status, int options);

```

> 参数说明



+ wait和waitpid都将暂停父进程，等待一个已经退出的子进程，并进行清理工作；

+ wait函数随机地等待一个已经退出的子进程，并返回该子进程的pid；

+ waitpid等待指定pid的子进程；如果为-1表示等待所有子进程。

+ status参数是传出参数，存放子进程的退出状态；



> 通常用下面的两个宏来获取状态信息：



+ WIFEXITED(status)		如果子进程正常结束，它就取一个非0值。传入整型值，非地址

+ WEXITSTATUS(status)	如果WIFEXITED非零，它返回子进程的退出码

+ options用于改变waitpid的行为，其中最常用的是WNOHANG，它表示无论子进程是否退出都将立即返回，不会将调用者的执行挂起。



> 例子.一个僵尸进程



```c

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>



void main()

{

    pid_t pid = fork();//创建一个子进程

    if(pid == 0)

    {

        exit(10);

    }else{

        sleep(10);

    }

}

//通过用ps –aux快速查看发现Z的僵尸进程。

```



> 例子２.避免僵尸进程（wait()函数）



```c

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>



void main()

{

    pid_t pid = fork();

    if(pid == 0)

    {

        exit(10);

    }else{

        wait(NULL);//表示等待所有进程

        sleep(10);

    }

}

```



> 例子3.利用信号处理避免僵尸进程（wait()函数）



```c

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>

#include<sys/wait.h>

#include<signal.h>



void SignChildPsExit(int iSignNo)

{

    int iExitCode;

    pid_t pid = wait(&iExitCode);//等待子进程的退出，没有这句话会出现僵尸进程

    printf("SignNo: %d  Child %d exit \n", iSignNo, pid);

    if(WIFEXITED(iExitCode))

    {

        printf("Child exited with code %d\n", WEXITSTATUS(iExitCode));

    }

    sleep(10);

}



int main()

{

    signal(SIGCHLD, SignChildPsExit);

    printf("Parent process id %d\n", getpid());

    pid_t iRet = fork();

    if(iRet == 0)

        exit(3);

}

```



> 例子4.waitpid实现



```c

#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>

#include<sys/wait.h>

#include<signal.h>



void SignChildPsExit(int iSignNo)

{

    int iExitCode;

    pid_t pid = waitpid(-1, NULL, 0); //表示等待任何进程，并阻塞，如果换成waitpid(-1, NULL, WNOHANG);则跟没有写waitpid效果类似，此时父进程没有阻塞

    printf("SignNo:%d, child %d exit\n", iSignNo, pid);

    if(WIFEXITED(iExitCode))

    {

        printf("Child exited with code %d\n", WEXITSTATUS(iExitCode));

        sleep(10);

    }

}





int main()

{

    signal(SIGCHLD, SignChildPsExit);

    printf("Parent process id:%d\n", getpid);

    pid_t iRet = fork();

    if(iRet == 0)

        exit(3);

}

```



###3.2.进程的终止

> 进程的终止有5种方式：



+ main函数的自然返回；

+ 调用exit函数

+ 调用_exit函数

+ 调用abort函数

+ 接收到能导致进程终止的信号ctrl+c SIGINT  ctrl+\ SIGQUIT



> 说明



+ 前三种方式为正常终止，后2种为非正常终止，但是无论哪种方式，进程终止时都将执行相同的关闭打开的文件，释放占用的内存等资源。只是后两种终止会导致程序有些代码不会正常的执行比如对象的析构、atexit函数的执行等



+ exit和_exit函数都是用来终止进程的。当程序执行到exit和_exit时，进程会无条件的停止剩下的所有操作，清除包括PCB在内的各种数据结构，并终止本程序的运行。



+ exit函数和_exit函数的最大区别在于exit函数在退出之前会检查文件的打开情况，把文件缓冲区中的内容写回文件，就是图中的“清理I/O缓冲”。



+ 由于linux的标准函数库中，有一种被称作“缓冲I/O”操作，其特征就是对应每一个打开的文件，在内存中都有一片缓冲区。每次读文件时，会连续读出若干条记录，这样在下次读文件时就可以直接从内存的缓冲区中读取；同样，每次写文件的时候，也仅仅是写入内存中的缓冲区，等满足一定的条件（如达到一定数量或遇到特定字符等），再将缓冲区中的内容一次性写入文件。这种技术大大增加了文件读写的速度，但也为编程带来了麻烦。比如有一些数据，认为已经写入文件，实际上因为没有满足特定的条件，它们还只是保存在缓冲区内，这时用_exit函数直接将进程关闭，缓冲区中的数据就会丢失。因此，如想保证数据的完整性，建议使用exit函数。



﻿

#四.进程间打开文件的继承

###4.1.用fork继承打开的文件

###4.2.守护进程










