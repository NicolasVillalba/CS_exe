//Real_Question1.c到Real_Question3.c是打听到的第一批复试上机试题，超级重点

//求 根号(3)+根号(5)+根号(7)+根号(9)+根号(10)+根号(11)的和

#include<stdio.h>
#include<math.h>//这个头文件一定带


int main()
{
    int n,i;
    double sum;//开根号以后是浮点数
    printf("请输入根号里面的数字：\n");
    for(i = 0; i < 6; i++)
    {
        scanf("%d", &n);
        sum += 1.0*sqrt(n);
    }
    printf("The sum is %.2lf\n", sum);//以小数点保留2位的格式输出
    return 0;
}
