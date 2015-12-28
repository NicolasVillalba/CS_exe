#include<stdio.h>
#include<string.h>

void fun(char *s, char *t)
{
    int cnt = 0;
    for(int i = 0; i < strlen(s); i += 2)
    {
        if(s[i]%2 == 0) t[cnt++] = s[i];
    }
    s[cnt] = '0';
}

int main()
{
     char s[] = "QiongzhouUniversity", t[100];
     fun(s, t);
     printf("%s\n", t);
     return 0;
}


