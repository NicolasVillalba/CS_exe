#include<stdio.h>
#include<string.h>

char* fun(char *s1, char *s2)
{
    int cnt = 0;
    for(int i = 0; s1[i] != '\0'; i++) cnt++;
    int tmpcnt = 0;
    for(int i = 0; s2[i] != '\0'; i++)
    {
        if(tmpcnt > cnt) return s2;
        tmpcnt++;
    }
    return s1;
}

int main()
{
    char s1[] = "asdkjhkgj";
    char s2[] = "adskfhwjbkhohh";
    printf("The longest string is %s\n", fun(s1, s2));
    return 0;
}
