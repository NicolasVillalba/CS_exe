#include<stdio.h>

int main()
{
int i;
int fact();
for(i=0;i<5;i++)
printf("\40:%d!=%d\n",i,fact(i));
return 0;
}

int fact(j)
{
int sum;
if(j==0)
sum=1;
else
sum=j*fact(j-1);
return sum;
}
