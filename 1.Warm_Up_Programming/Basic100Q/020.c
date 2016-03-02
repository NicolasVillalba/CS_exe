#include<stdio.h>
#define max 100

int fun(int lim, int aa[max])
{
    int n = 0;
    if(lim >= 2) aa[n++] = 2;
    if(lim >= 3) aa[n++] = 3;
    for(int i = 5; i <= lim; i++)
    {
        int cnt = 0;
        for(int j = 2; j < i - 1; j++)
        {
            if(i % j == 0)
            {
                 cnt++;
                 break;
            }

        }
        if(cnt == 0) aa[n++] = i;
    }
    return n;
}

int main()
{
     int aa[max];
     for(int i = 0; i < max; i++)
         aa[max] = 0;
     int n = fun(max, aa);
     printf("there are %d primer number\n", n);
     for(int i = 0; i < max && aa[i] != 0; i++)
     {
          int cnt = 0;
          if(cnt % 10 == 0) printf("\n");
          printf("%d", aa[i]);
          cnt++;
     }
     printf("\n");
     return 0;
}
