//文件读写都是有一定的套路的，参考那本红色c语言书，请牢记以下读写文件

//**重点看c语言书的338页的10.1题**，**339页的10.2题**，**346页的10.4题**，那个代码一定要自己在编译器里面敲一遍然后运行
//

#include<stdio.h>


int main()
{
    FILE *fp;//创建一个文件指针，前面那个FILE一定是大写的
    fp = fopen("test.txt", "r");
    //重点语句fopen("test.txt", "r");一共有2个变量，第一个是文件名字（文件要和代码存储在同一个文件夹里面），第二个变量是读写类型，r=read，w=write，这里是打开一个文件是读,只读打开的话只能读取文件里面的信息，不能写进入
    //
    
    
    
    if(NULL == fp){//这里是判断这个文件有没有被程序打开，如果没有打开则打印没打开的信息，然后退出程序运行
        perror("open failed！\n");
        return 0;
    }else{
        printf("Open success!\n");
    }
    
    return 0;
    
}
