#include<stdio.h>
#define m 101

int fun(int a[])
{
    int n = 0;
    for(int i = 1; i < m; i++)
        if((i%7==0||i%11==0) && !(i%7==0&&i%11==0)) a[n++] = i;
    return n;
}

int main()
{
    int a[m];
    for(int i = 0; i < m; i++) a[i] = 0;
    int n = fun(a);
    printf("There are %d numbers satisfy the question.\n", n);
    for(int i = 0; i < m; i++)
    {
        if(a[i] == 0) break;
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
