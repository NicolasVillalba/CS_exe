#include<stdio.h>
#include<string.h>

void fun(char *s)
{
    int cnt = 0;
    for(int i = strlen(s) - 1; s[i] == '*'; i++)
        cnt++;
    s[strlen(s) - 1 - cnt -1] = '\0';
}

int main()
{
    char s[] = "****sfgsdfg****sdfdf***";
    fun(s);
    printf("%s\n", s);
    return 0;
}
