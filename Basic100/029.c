#include<stdio.h>
#include<string.h>

void fun(char *ss)
{
    int n = strlen(ss);
    for(int i = 1; i < n; i += 2)
    {
        if(ss[i] >= 'a' && ss[i] <= 'z')
            ss[i] = ss[i] - 'a' + 'A';//将小写变成大写
    }
}

int main()
{
     char ss[] = "abc4EFg";
     fun(ss);
     printf("%s\n", ss);
     return 0;
}
