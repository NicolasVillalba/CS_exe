#include<stdio.h>

int main()
{
int n,t,number=20;
float a=2,b=1,s=0;
for(n=1;n<=number;n++)
{
s=s+a/b;
t=a;a=a+b;b=t;/*这部分是程序的关键,请读者猜猜 t 的作用*/
}
printf("sum is %9.6f\n",s);

return 0;
}
