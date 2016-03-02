#include<stdio.h>
#define m 1000

int fun(int xx[], int n)
{
    int cnt = 0;
    for(int i = 3; i < n; i++)
    {
        for(int j = 2; j < i; j++)
            if(i % j == 0) xx[cnt++] = i;
    }
    return cnt;
}

int main()
{
    int xx[m];
    for(int i = 0; i < m; i++)
        xx[i] = 0;
    int n = fun(xx, 17);
    printf("%d\n",n);
    for(int i = 0; xx[i] != 0; i++)
        printf("%d ",xx[i]);
    printf("\n");
    return 0;
}
