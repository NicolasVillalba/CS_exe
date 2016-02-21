#include<stdio.h>

void fun(char *s)
{
    int cnt = 0;
    for(int i = 0; ; i++)
    {
        if(s[i] == '*') cnt++;
        else break;
    }
    int k = 0;
    for(int i = cnt; s[i] != '\0'; i++)
        s[k++] = s[i];
    for(int i = k; s[i] != '\0'; i++)
        s[i] = '*';
}

int main()
{
     char s[] = "*****A*BC*DEF*G";
     fun(s);
     printf("%s\n", s);
     return 0;
}

