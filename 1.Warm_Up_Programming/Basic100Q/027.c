#include<stdio.h>
#define n 100

int fun(int a[n], int m, int *k)
{
    *k = 0;
    for(int i = 0; i <= m; i++)
    {
        if(i % 7 == 0 || i % 11 == 0) a[(*k)++] = i;
    }
    return *k;
}

int main()
{
    int a[n];
    for(int i = 0; i < n; i++) a[i] = 0;
    int m = 0;
    scanf("%d",&m);
    while(m <= 0 || m >= 100)
    {
        printf("Please input a integer between 1 and 100:\n");
        scanf("%d", &m);
    }
    int cnt = 0;
    fun(a, m, &cnt);
    for(int i = 1; i < cnt; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
