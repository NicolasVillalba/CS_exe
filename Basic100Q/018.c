#include<stdio.h>
#define n 3

void reverse(int a[n][n])
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
        {
            if(i == j) continue;
            else{
                int tmp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = tmp;
            }
        }
}

int main()
{
    int a[n][n]={
        1,2,3,
        4,5,6,
        7,8,9
    };
     reverse(a);
     for(int i = 0; i <n; i++)
    {
         for(int j = 0; j < n; j++)
             printf("%d ",a[i][j]);
         printf("\n");
    }
     return 0;
}
