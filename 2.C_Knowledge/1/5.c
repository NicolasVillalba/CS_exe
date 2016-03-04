#include<stdio.h>

int main()
{
    int a[12] = {2,3,4,5,8,9,10,23,99,35,44,22};
    int max = a[0],min = a[0];
    for(int i = 0; i < 12; ++i)
    {
        max = (max < a[i])?a[i]:max;
        min = (min > a[i])?a[i]:min;
    }
    int SeMax = -1;
    for(int i = 0; i < 12; ++i)
    {
         if(a[i] == max) a[i] = min;
         SeMax = (SeMax < a[i])?a[i]:SeMax;
    }

    printf("The max is %d, the second max is %d\n", max, SeMax);
    return 0;
}
