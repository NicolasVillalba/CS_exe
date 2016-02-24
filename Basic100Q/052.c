#include<stdio.h>
#include<string.h>
#define C 300

void fun(char *p1, char *p2, char *p)
{
    p = p1;
    int i;
    int cnt = 0;
    for(i = strlen(p1);p2[cnt] != '\0'; i++)
        p[i] = p2[cnt++];
    p[i] = '\0';
}

int main()
{
     char p1[] = "wlfkshjH---";
     char p2[] = "sdkjhakjgdksddssdaz";
     char p[C];
     fun(p1, p2, p);
     printf("%s + %s =\n", p1, p2);
     printf("%s%s\n",p1,p2);
     return 0;
}
