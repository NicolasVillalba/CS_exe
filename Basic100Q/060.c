#include<stdio.h>
#define N 10

int fun(int a[], int b[])
{
    int n = 0;
    int tmp = 0;
    int cnt = 0;
    for(int i = 0; i < 18; i++)
        if(a[i] != tmp)
        {
            b[n++] = a[i];
            tmp = a[i];
        }else{
            cnt++;
        }
    return cnt;
}

int main()
{
     int a[] = {2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10};
     int b[N];
     int n = fun(a, b);
     for(int i = 0; i < n; i++)
         printf("%d ", b[i]);
     printf("\n");
     return 0;
}
