#include<stdio.h>
#include<string.h>
#define MAXD 100
int main()
{
    char str1[MAXD],str2[MAXD];     //用于保存键盘输入的两个待加大整数
    int num1[MAXD],num2[MAXD];
    while(1)
    {
        memset(str1,0,sizeof(str1));
        memset(str1,0,sizeof(str2));
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));//将这些数组清零
        scanf("%s",str1);
        scanf("%s",str2);
        int len1,len2,i,j;
        len1=strlen(str1);
        len2=strlen(str2);
        j=0;
        int max=len1>len2?len1:len2;
        for(i=len1-1; i>=0; i--)
            num1[j++]=str1[i]-'0';
        /*字符串反转并且转换为数字保存到数组里面*/
        j=0;
        for(i=len2-1; i>=0; i--)
            num2[j++]=str2[i]-'0';
        for(i=0; i<max; i++)
        {
            num2[i]+=num1[i];//相加
            if(num2[i]>=10)
            {
                num2[i]-=10;
                num2[i+1]+=1;//产生进位
            }
        }
        if(num2[max]) printf("%d",num2[max]);//如果最高位产生进位
        for(i=max-1; i>=0; i--)
            printf("%d",num2[i]);
        printf("\n");
    }
    return 0;
}


