#include<stdio.h>
#include<string.h>

void fun(char *s, char *t)
{
    int rearn = 0;
    int cnt = 0;
    for(int i = strlen(s) - 1; s[i] == '*'; i++)
        rearn++;
    int frontn = 0;
    for(int i = 0; s[i] == '*'; i++)
    {
        t[cnt++] = s[i];
        frontn++;
    }
    for(int i = frontn - 1; i < strlen(s) - rearn; i++)
        if(s[i] != '*') t[cnt++] = s[i];
    for(int i = strlen(s) - rearn - 2; s[i] != '\0'; i++)
        t[cnt++] = '*';
    t[cnt] = '\0';
}

int main()
{
    char s[] = "****ABCD**EFG***";
    char t[100];
    fun(s, t);
    printf("%s\n", t);
    return 0;
}
