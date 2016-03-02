#include<stdio.h>

void fun(char a[], char b[], int n)
{
    int m = 0;
    for(int i = 0; a[i] != '\0'; i++)
        if(i != n) b[m++] = a[i];
    b[m] = '\0';
}

int main()
{
    char *a = "ilovecskaoyan.com",b[50];
    fun(a, b, 10);
    printf("a: %s\nb: %s\n", a, b);
    return 0;
}
