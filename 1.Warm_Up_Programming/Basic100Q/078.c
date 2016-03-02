#include<stdio.h>
#include<string.h>


void fun(char *s, char *t)
{
    int cnt = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] % 2 != 0) t[cnt++] = s[i];
    }
    t[cnt] = '\0';
}

int main()
{
    char s[] = "dskjhaskdhwboi12e676ybmdn3";
    char t[100];
    fun(s, t);
    printf("%s\n",t);
    return 0;
}
