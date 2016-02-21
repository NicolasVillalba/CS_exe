#include<stdio.h>
#include<string.h>
#define max 100

int fun(char *s, char r)
{
    int cnt = 0;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == r) cnt++;
    return cnt;
}

int main()
{
    char s[] = "123412132";
    char r = '1';
    int n = fun(s, r);
    printf("%d\n", n);
    return 0;
}
