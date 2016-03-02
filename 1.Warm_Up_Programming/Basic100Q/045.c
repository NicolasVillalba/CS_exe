#include<stdio.h>

void fun(char *s, int n, int h, int e)
{
    int tmpcnt = 0;
    int i = 0;
    for(i = h; i < n; i++)
        s[i -h] = s[i];
    s[i] = '\0';
    s[n - e - h] = '\0';
}

int main()
{
    char s[] = "*****wlf**csh****";
    fun(s, 17, 5, 4);
    printf("%s\n", s);
    return 0;
}
