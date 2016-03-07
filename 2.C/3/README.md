> 1.实现  mystrcpy(), mystrcmp(), mystrcat(), mystrlen();

```c
#include<stdio.h>

char *mystrcpy(char *s,const char *t, int n)
{
    int i;
    for(i = 0; i < n && t[i] != '\0'; i++)
        s[i] = t[i];
    for(; i < n; i++)
        s[i] = '\0';
    return s;
}

int mystrcmp(const char *s, const char *t)
{
    for(int i = 0; s[i] != '\0' && t[i] != '\0'; i++)
    {
        if(s[i] > t[i]) return 1;
        else if(s[i] < t[i]) return -1;
    }
    return 0;
}

char *mystrcat(char *s, const char *t, int n)
{
    int m = 0;
    for(;s[m] != '\0'; m++);

    int i;
    for(i = 0; i < n && t[i] != '\0'; i++)
        s[m + i] = t[i];
    s[m + i] = '\0';

    return s;
}


int mystrlen(const char *s)
{
    int cnt = 0;
    while(s[cnt] != '\0') cnt++;
    return (cnt + 1);
}


int main()
{
     printf("test mystrcpy:\n");
     char s1[30] = "";
     char t1[22] = "testMystrcpyisSuccess";
     mystrcpy(s1, t1, 22);
     printf("%s\n", s1);


     printf("test mystrcmp:\n");
     char s2[4] = "abc";
     char t2[4] = "abd";
     int n = mystrcmp(s2, t2);
     if(n == 0) printf("The are equal.\n");
     else if(n == 1) printf("s2 is more than t2.\n");
     else printf("s2 is less than t2.\n");

     printf("test mystrcat:\n");
     char s3[30] = "My name is ";
     char t3[10] = "Wanglifei";
     mystrcat(s3, t3, 10);
     printf("%s\n", s3);

     printf("test mystrlen:\n");
     char s4[] = "theismylastfunction";
     int cnt = mystrlen(s4);
     printf("s4 have %d letters.\n", cnt);
     return 0;
}

```

> 2.输入一行字符串（单词和若干空格）， 输出该行单词个数。
Input：____hello_________world_ how___are___you___\n
Output:   5

```c
#include<stdio.h>

int countWord(const char *s)
{
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++) 
        if(s[i] == ' ')cnt++;
    if(s[0] == ' ') cnt--;
    return cnt;
}

int main()
{
     char s[] = " hello world how are you ";
     int cnt = countWord(s);
     printf("there is %d letters total.\n", cnt);
     return 0;
}
```


> 3.输入一行字符串（单词和若干空格），输出该行单词（每个单词一行）
Input：____hello_________world_ how___are___you___\n
Output:   hello
			 world
			 how
			 are
			 you

```c
#include<stdio.h>

int countWord(const char *s)
{
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ')
        {
            cnt++;
            if(i!=0) printf("\n");
        }else printf("%c", s[i]);
    }
    if(s[0] == ' ') cnt--;
    return cnt;
}

int main()
{
     char s[] = " hello world how are you ";
     int cnt = countWord(s);
     printf("there is %d letters total.\n", cnt);
     return 0;
}
```


> 4:输入一行字符串，把字符串翻转 。
Input: I____am__a__student
Output: student__a__am____I

```c
#include<stdio.h>
//翻转，其实也是逆置，利用2个指针，分别从两端移动相遇前都交换相互指向的元素
void Reverse(char *pBegin, char *pEnd)
{
    if(pBegin == NULL || pEnd == NULL) return;

    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++, pEnd--;
    }
}

//翻转句子，也调用了上面的翻转函数
char *ReverseSentence(char *pData)
{
    if(pData == NULL) return NULL;

    //获得首指针
    char *pBegin = pData;

    //获得尾指针
    char *pEnd = pData;
    while(*pEnd != '\0') pEnd++;
    pEnd--;

    Reverse(pBegin, pEnd);//逆置句子

    pBegin = pEnd = pData;//逆置单词
    while(*pBegin != '\0')
    {
         if(*pBegin == ' ')
         {
             pBegin++;
             pEnd++;
         }else if(*pEnd == ' ' || *pEnd == '\0')
         {
              Reverse(pBegin, --pEnd);
              pBegin = ++pEnd;
         }else pEnd++;
    }
    return pData;
}

int main()
{
     char s[] = "I am a student.";
     ReverseSentence(s);
     printf("%s\n", s);
     return 0;
}

```

