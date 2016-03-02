#include<stdio.h>

void fun(char *a, int p)
{
    char s[p+1];
    int n = 0;
    for(int i = 0; i < p; i++)
        s[n++] = a[i];
    int k = 0;
    for(int i = n; a[i] != '\0'; i++)
        a[k++] = a[i];
    int m = 0;
    for(int i = k; a[i] !='\0'&&s[m] != '\0'; i++)
        a[i] = s[m++];
}

int main()
{
     char a[] = "ABCDEFGHIJK";
     int p = 3;
     fun(a, p);
     for(int i = 0; a[i] != '\0'; i++)
         printf("%c ", a[i]);
     printf("\n");
     return 0;
}
