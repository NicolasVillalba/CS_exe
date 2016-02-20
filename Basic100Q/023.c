#include<stdio.h>
#include<string.h>


int fun(char *str)
{
    int n = 0;
    for(int i = 0; i < strlen(str)/2; i++)
    {
        if(str[i] != str[strlen(str) - 1 - i])
        {
            n++;
            break;
        }
    }
    if(n == 0) return 1;
    else return 0;
}

int main()
{
    char str[] = "wlflw";
    char str2[] = "wlf";
    int k = fun(str);
    int k2 = fun(str2);
     if(k == 1) printf("YES\n");
     else printf("NO\n");

     if(k2 == 1) printf("YES\n");
     else printf("NO\n");
     return 0;
}
