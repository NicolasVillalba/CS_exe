#include<stdio.h>
#include<stdlib.h>
#define n 10

int main()
{
    int a[n] = {1,4,3,5,6,7,8,100,2,3};
    int x = a[0],y = a[1];
    int ret = abs(x - y);
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            if((abs(a[i] - a[j]) < ret) && a[i] != a[j])
            {
                 x = a[i];
                 y = a[j];
                 ret = abs(x - y);
            }
        }
    }
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
