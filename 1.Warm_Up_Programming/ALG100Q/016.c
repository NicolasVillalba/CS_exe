#include<stdio.h>

int main()
{
    int m, n;
    printf("please input two integer:\n");
    scanf("%d %d", &m, &n);
    if(m < n);
    {
        int tmp = n;
        n = m;
        m = tmp;
    }
    int count = m *n;
    while(n != 0)
    {
         int tmp = m % n;
         m = n;
         n = tmp;
    }
    printf("gongyueshu:%d\n", m);
    printf("gongbeishu:%d\n", count /m);
    return 0;
}
