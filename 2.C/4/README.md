> 1.将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。例如“ h1ell2o3” ->”123hello”

[答案](1.c)

> 2.将 字 符 串 中 的 空 格 替 换 成 “%020” ， 例 如 “hello world how ”->”hello%020%020%020world%020%020%020how%020%020%020%020”

[答案](2.c)

> 3.删除字符串中指定的字符。 例如 “ abcdaefaghiagkl“ 删除‘a’,以后： “ bcdefghigkl”

[答案](3.c)

> 4.删除一个数组中重复的元素。例如 1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 -> 1,2,3,4,5,6

[答案](4.c)

> 5.. 将 字 符 串 中 的 相 邻 的 多 余 空 格 去 掉 ， 例 如 （空 格 用 下 划 线 表示）： ”___hello____world___how_are_you__” ->”hello_world_how_are_you”

[答案](5.c)


> 6.附加题：大整数加法。 实现任意范围的两个整数的加法（ 整数的范围用 int 型的变量无法表示）

[答案](6.c)


> 从（0,0）到（m,n),每次走一步，只能向上或者向右走，有多少种路径走到(m,n)
(0,0) ->(2,2)
0.0- >1.0 ->2.0 ->2,1 ->2,2       1
0,0->1.0->1,1 ->2.1->2.2    2
0.0 -> 1.0 ->.1,1->1,2->2,2   3
0.0 -> 0.1- >0.2- >1.2 ->2.2   4
0.0 ->0.1 ->1.1->1.2->2.2  5
求f(m,n)方法

[答案](7.c)

```c
//1题目
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *convert(char *s)
{
	char t[10];
	int j, i;
	for(i = strlen(s) - 1; i > 0; i--)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
				for(int j = i; j > 0; j--)
				{
					if(s[j] < s[j - 1])
					{
						char temp = s[j];
						s[j] = s[j - 1];
						s[j - 1] = temp;
					}
				}
		}
	}
	return s;
}


int main()
{
	char s[] = "h1ell2o3";
	convert(s);
	printf("%s\n",s);
	return 0;
}
```

```c
//2题目
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void Replace(char *s)
{
	int n = strlen(s);
	for(int i = 0; i < n; i++)
 	{
		if(s[i] != ' ') printf("%c", s[i]);
		else printf("%%020");
	}
}


int main()
{
	char s[] = "hello world how ";
	Replace(s);
	return 0;
}
```
```c
//3题目
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *DeleteA(char *s)
{
	int lenth = strlen(s);
	int i, j = 0;
	for(i = 0; i < lenth; i++)
		if(s[i] != 'a') s[j++] = s[i];
	s[j] = '\0';
	return s;
}


int main()
{
	char s[] = " abcdaefaghiagkl";
	DeleteA(s);
	printf("%s\n", s);
	return 0;
}


```
```c
//4题目
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 15

int j = 1;

int *DeleteRepeatN(int *a)
{
	int i;
	int temp = a[0];
	for(i = 1; i < n; i++)
	{
		if(a[i] == temp) continue;
		else{
			temp = a[i];
			a[j++] = a[i];
		}
	}
	return a;
}


int main()
{
	int a[n] = {1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6};
	DeleteRepeatN(a);
	printf("%d", a[0]);
	for(int i = 1; i < j; i++ )
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
```
```c
//5题目
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *DeleteSpace(char *s)
{
	int lenth = strlen(s);
	int j = 0;
	int i = 1;
	while(i != lenth-1)
	{
		if(s[0] == ' ')  s[j++] = s[i++];
		
		if(s[i] != ' ') s[j++] = s[i];
		if(s[i] == ' ')
		{
			s[j++] = ' ';
			while( s[i] == ' ') i++;
		}else i++;
	}
	if(s[lenth - 1] == ' ') s[j] = '\0';
	else {
		s[j++] = s[lenth - 1]; s[j] = '\0';
	}
	return s;
}

int main()
{
	char s[] = " hello  world   how are you ";
	DeleteSpace(s);
	printf("%s", s);
	printf("*\n");
	return 0;
}
```
```c
//6题目
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


```
```c
//7题目
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int Count(int n, int m)
{
	while(n != 0 && m != 0)
	{
		return (Count(n - 1, m) + Count(n, m - 1));
	}
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int count = Count(n, m);
	printf("%d\n", count);
	return 0;
}

```

