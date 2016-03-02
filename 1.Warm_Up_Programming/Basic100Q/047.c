#include<stdio.h>
#include<string.h>

void fun(char *ss)
{
    for(int i = 1; i < strlen(ss); i += 2)
    {
        if(ss[i] <= 'z' && ss[i] >= 'a')
            ss[i] -= 32;
    }
}

int main()
{
    char ss[] = "abc4EFgh";
    fun(ss);
    printf("%s\n", ss);
    return 0;
}
