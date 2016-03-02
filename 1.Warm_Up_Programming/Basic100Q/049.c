#include<stdio.h>
#include<string.h>

void fun(char *s, char *t)
{
    int i = 0;
    int cnt = 0;
    while(s[i] != '\0')
    {
        if(i % 2 != 0 || s[i] % 2 == 0)
            t[cnt++] = s[i];
        ++i;
    }
}

int main()
{
     char s[] = "ABCDEFGH12345";
     char t[256];
     fun(s, t);
     printf("%s : %s\n", s, t);
     return 0;
}
