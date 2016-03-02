#include<stdio.h>

void fun(char *s)
{
    int cnt = 0;
    for(int i = 0; s[i] == '*'; i++)
        cnt++;
    int i;
    for(i = cnt; s[i] != '\0'; i++)
        s[i - cnt] = s[i];
    s[i - 2] = '\0';
}

int main()
{
    char s[] = "***abcdef*g***";
    fun(s);
    printf("%s\n", s);
     return 0;
}
