#include<stdio.h>
#define n 10

int main()
{
    int cnt = 0;
    int maxCnt = 1;
    int a[n] = {3,3,3,3,35,6,7,8,3,3};
    int max = a[0];
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            if(a[i] == a[j]) cnt++;
        }
        if(cnt > maxCnt)
        {
             maxCnt = cnt;
             max = a[i];
        }
        cnt = 0;
        if(maxCnt > n/2) break;
    }
    printf("The number is %d\n",max);
    return 0;
}
