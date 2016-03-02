#include<stdio.h>

void fun(char *s, char *t)
{
    int cnt = 0;
    for(int i = 0; s[i] == '*'; i++)
        cnt++;
    int n = 0;
    for(int i = 0; i < cnt; i++)
        t[n++] = '*';
    for(int i = cnt; s[i] != '\0'; i++)
        if(s[i] != '*') t[n++] = s[i];
    t[cnt] = '\0';
}

int main()
{
    char s[] = "****wlfsdfgf*sss*sssdflw****";
    char t[100];
    fun(s, t);
    printf("%s\n", t);
    return 0;
}
