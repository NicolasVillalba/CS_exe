#include<stdio.h>
#define M 10

int fun(int a[2][M])
{
    int n = a[0][0];
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < M; j++)
            if(n < a[i][j]) n = a[i][j];
    return n;
}

int main()
{
    int a[2][M] = {
        1,3,5,7,8,10,11,2,4,8,
        2,6,10,14,18,20,22,2,4,8
    };
    int max = fun(a);
    printf("the maxism number is %d\n", max);
    return 0;
}
