#include<stdio.h>

void fun(char *s, char *t)
{
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] != '*') t[cnt++] = s[i];
    t[cnt] = '\0';
}

int main()
{
    char s[] = "sdkfhkash*********DFgsg***";
    char t[100];
    fun(s, t);
    printf("%s\n", t);
    return 0;
}
