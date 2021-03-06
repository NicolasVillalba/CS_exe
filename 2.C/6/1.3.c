//本体是对数组中的元素进行排序
//考点：冒泡排序
//利用第二题的数组排序，即本题是利用1.2.c题目进行延伸，要求最后的数组有序


#include<stdio.h>


int main()
{
    int c[10] = {3,6,2,1,4,5,3,9,56,10};
    
    //冒泡排序，是重点
    //冒泡排序的思想是像鱼吐泡泡，将大的数字放到后面去。
    int i,j;
    for(i = 0; i < 10; i++)//首先i从数组首元素开始，到最后结束
    {
        for(j = i+1; j < 10; j++)//然后j从i的下一个开始遍历到最后
        {
            if(c[i] > c[j])//假如前面一个比后面一个大，就交换他们使得前面一个小于后面一个
            {
                //此三句代码为交换两个数字的过程
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    
   //输出排序好的数组
   for(i = 0 ; i < 10; i++)
   {
        printf("%d ", c[i]);
   }
   printf("\n");
   return 0;
}
