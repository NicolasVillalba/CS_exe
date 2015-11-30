#include<stdio.h>

void fun(int m, int k, int xx[])
{
    int s = 0;
    for(int i = m + 1; ; i++)
    {
        if(s == k) break;
        int count = 0;
        for(int j = i - 1; j > 2; j--)  if(i % j == 0) count++;
        if(count == 0) xx[s++] = i;
    }
}

int main()
{
     int primer[100];
     for(int i = 0; i < 100; i++) primer[i] = 0;
     fun(10, 90, primer);
     for(int i = 0; i < 100; i++)
         if(primer[i] == 0) break;
         else printf("%d ", primer[i]);
     printf("\n");
     return 0;
}
