#include<stdio.h>
#define n 1001

int main()
{
    int a[n];
    int b[n];
    b[0] = 0;
    for(int i = 1; i < n; ++i)
    {
        a[i] = i;
        b[a[i]]=1;
    }
    scanf("%d", &a[0]);
    b[a[0]]++;
    for(int i = 1; i < n; ++i)
    {
         if(b[i] == 2)
         {
             printf("%d\n", i);
             break;x
         }
    }
    return 0;

}
