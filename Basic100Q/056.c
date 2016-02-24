#include<stdio.h>
#include<string.h>

void fun(char *s, int p, char *t)
{
    int n = 0;
    int cnt = 0;
    for(int i = p; s[i] == '*'; i--)
        cnt++;
    for(int i = 0; i < strlen(s) - cnt; i++)
        if(s[i] != '*') t[n++] = s[i];
    for(int i = 0; i < cnt; i++)
        t[n++] = '*';
    t[n] = '\0';
}

int main()
{
    char s[] = "*****dfa****sdf******";
    char t[100];
    int p = strlen(s);
    fun(s, p, t);
    printf("%s\n",t);
    return 0;
}
