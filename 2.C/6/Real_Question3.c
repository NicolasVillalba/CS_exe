//第三题是从文件读入一些字符，然后以从小到大的顺序输出到控制台（就是程序运行的时候那个黑黑的窗口）


//题目思路，将文件的字符读入存储在数组中，然后利用冒泡排序给数组排序，最后输出有顺的数组
#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt", "r");// 打开文件，后面需要关闭
    if(fp == NULL)//判断文件是否打开成功
    {
        printf("file open failed!\n");//加入打开失败则输出这个语句
        return 0;//然后程序结束
    }
    
    
    //文件打开成功则继续以下操作
    
    
    
    //以下为读入以后存储到数组里面
    char b[11];//存储那十个需要排序的字母，最后一个位置存储'\0'，即字符串结束标识符
    
    fgets(b, sizeof(b), fp);//读取文件里面的字符串，并且存储在字符串数组b中
    
    
    fclose(fp);//关闭文件
    
    
    //以下为读完了之后对数组进行冒泡排序，按照abcd...的顺序排列
    for(int i = 0; i < 10; i++)
    {
        for(int j = i + 1; j < 10; j++)
        {
            if(b[i] > b[j])
            {
                char temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    
    
    //最后输出数组
    for(int i = 0; i < 10; i++)
    {
        printf("%c", b[i]);
    }
     printf("\n");
    return 0;
}
