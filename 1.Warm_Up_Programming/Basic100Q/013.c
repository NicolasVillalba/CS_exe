#include<stdio.h>
#define m 10
#define n 10

void fun(int tt[m][n], int pp[n])
{
    for(int j = 0; j < n; j++)
    {
        int tmp = tt[0][j];
        for(int i = 0; i < m; i++)
            if(tmp > tt[i][j]) tmp = tt[i][j];
        pp[j] = tmp;
    }
}

int main()
{
     int tt[m][n];
     int pp[n];
     for(int i = 0; i < n; i++)
     {
          pp[i] = 0;
          for(int j = 0; j < m; j++)
              tt[i][j] = (i+1) * (j + 1);
     }
     fun(tt,pp);
     for(int i = 0; i < n; i++)
         printf("%d ", pp[i]);
     printf("\n");
     return 0;
}
