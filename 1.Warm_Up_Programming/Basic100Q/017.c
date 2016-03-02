#include<stdio.h>
#include<string.h>

void fun(char *s)
{
    for(int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int main()
{
     char s[] = "123456789";
     fun(s);
     printf("%s\n",s);
     return 0;
}
