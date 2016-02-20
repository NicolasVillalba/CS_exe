#include<stdio.h>
#define m 100

void fun(int x, int pp[], int *n)
{
    *n = 0;
    for(int i = 1; i < x; i += 2)
        if(x%i==0) pp[(*n)++] = i;
}

int main()
{
    int n,x = 99;
    int pp[m];
    fun(x, pp, &n);
    for(int i = 0; i < n; i++) printf("%d ", pp[i]);
    printf("\n");
    return 0;
}
