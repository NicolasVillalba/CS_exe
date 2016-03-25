##一.GDB的功能
 
1、 启动你的程序，可以按照你的自定义的要求随心所欲的运行程序。
2、 可让被调试的程序在你所指定的调置的断点处停住。
3、 当程序被停住时，可以检查此时你的程序中所发生的事
 
> 实例程序:test.c

```c
#include <stdio.h>
int func(int n){
    int sum=0,i;
    for(i=0; i<n; i++)
    {
        sum+=i;
    }
    return sum;
}

main()
{
    int i;
    long result = 0;
    for(i=1; i<=100; i++)
    {
        result += i;
    }
    printf("result[1-100] = %d /n", result );
    printf("result[1-250] = %d /n", func(250) );
}

```

> 编译生成可执行程序: 

```sh
gcc -g test.c -o exe
#注意：参数 –g
```
 

##二.GDB命令：


|命令|解释|
|---|-------------------------|
|l |list|
|b |break|
|    |1）break  linenumber|
|    |2）break  function_name|
|    |3) disable breakpoints number
|    |4) enable breakpoints number|
|n |next|
|s |step|
|r |run|
|p |print|
|c |continue|
|q |quit|
|bt |backtrace|
|info||
|x/4bx &变量 |  以16进制查看内存存储|



##三.启动GDB的方法(先介绍前两种，后一种再写后台程序之前介绍)：

+ 1、gdb <program>
program也就是你的执行文件，一般在当然目录下。

+ 2、gdb <program> core
用gdb同时调试一个运行程序和core文件，core是程序非法执行后core dump后产生的文件。

+ 3、gdb <program> <PID>
如果你的程序是一个服务程序，那么你可以指定这个服务程序运行时的进程ID。gdb会自动attach上去，并调试他。program应该在PATH环境变量中搜索得到。

 

##四.Coredump 举例

```c
#include <stdio.h>
int main(void)
{
printf("hello world! dump core for set value to NULL pointer/n");
*(char *)0 = 0;
return 0;
}
```

> 如何设置core dump文件

 
```sh
#1． 
Ulimit –a

#2． 
Ulimit –c 102400

#3． 
Ulimit –c unlimited

gdb ./test2 core
```
