#include<stdio.h>

int fun(char *s)
{
    int cnt = 1;
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == ' ') cnt++;
    return cnt;
}

int main()
{
    char s[] = "wlf csh love";
    int n = fun(s);
    printf("%d\n",n);
    return 0;
}
