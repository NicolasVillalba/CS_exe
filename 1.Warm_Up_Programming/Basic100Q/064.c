#include<stdio.h>
#include<string.h>

void fun(char *s, char *t)
{
    int n = 0;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] % 2 == 0) t[n++] = s[i];
    t[n] = '\0';
}

int main()
{
    char s[] = "asdfasdfsadjgwgm,vmmhwbmbmb";
    char t[100];
    fun(s, t);
    printf("%s\n", t);
    return 0;
}
