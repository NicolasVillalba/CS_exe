#include<stdio.h>
#include<string.h>

void fun(char *s, int n)
{
    int cnt = 0;
    int i;
    for(i = strlen(s) - 1;; i--)
    {
        if(s[i] != '*') break;
        cnt++;
    }
    if(cnt > n) s[i + n +1] = '\0';
}

int main()
{
     char s[] = "****A*BC*DEF*G****";
     int m;
     printf("please input a integer\n");
     scanf("%d", &m);
     fun(s, m);
     printf("%s\n", s);
     return 0;
}
