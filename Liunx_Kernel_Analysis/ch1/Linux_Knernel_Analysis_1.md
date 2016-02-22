
####原创作品转载请注明出处

####汪利飞《Linux内核分析》MOOC课程http://mooc.study.163.com/course/USTC-10000290


##一. 32位部分存储器小结

1.EAX 是"累加器"(accumulator), 它是很多加法乘法指令的缺省寄存器。

2.EBX 是"基地址"(base)寄存器, 在内存寻址时存放基地址。

3.ECX 是计数器(counter), 是重复(REP)前缀指令和LOOP指令的内定计数器。

4.EDX 则总是被用来放整数除法产生的余数。

5.ESI/EDI分别叫做"源/目标索引寄存器"(source/destination index),因为在很多字符串操作指令中, DS:ESI指向源串,而ES:EDI指向目标串.
EBP是"基址指针"(BASE POINTER), 它最经常被用作高级语言函数调用的"框架指针"(frame pointer).




##二. 寻址方式小结

1、寄存器寻址
操作数在通用寄存器中。
例：

```c
movl %eax,%edx
//相当于
edx = eax
```

2、立即寻址
指令的地址字段指出操作数本身，而不是操作数地址，不需要访问内存取数，因此指令执行时间很短。
例：

```c
movl $0x123,%eax
//$符号指的是在操作数本身,而不是操作地址
```

3、直接寻址
指令的地址字段直接指出操作数的内存地址，不需要其他转换。
例：

```c
movl 0x123,%eax
//取分立即寻址,没有$符号指的是操作数为该地址所指的值.
```

4、间接寻址
相对直接寻址而言，指令的地址字段不是操作数的真正地址，而是操作数地址的指示器。形式地址单元的内容才是操作数的有效地址。
例：

```c
movl (%ebx),%edx
```


##三. 将c语言编译成汇编语言
[汇编语言AT&T与Intel语法区别参考](http://www.ibm.com/developerworks/cn/linux/l-assembly/)

```c
//main.c
int g(int x)
{
    return x + 210;
}

int f(int x)
{
    return g(x);
}

int main()
{
    return f(210) + 210;
}
```
![main.c](shell_ch1_c.png)

```c
//main.s汇编语言,本例是删除.*文件,利于分析纯汇编语言
g:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$210, %eax
	popl	%ebp
	ret
f:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	g
	leave
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$210, (%esp)
	call	f
	addl	$210, %eax
	leave
	ret
```
![main.s](huibian_main_s_after.png)

##四. 汇编语言工作过程
![explain](explain_for_the_s_in_kernel_ch1.gif)
