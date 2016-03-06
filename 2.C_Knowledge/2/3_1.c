#include<stdio.h>

void DecimaltoBinary(int a)
{
    long int ret = 0;
    int cnt = 1, n = a;
    while(a != 0)
    {
        int tmp = a%2;
        ret += tmp * cnt;
        cnt *= 10;
        a /= 2;
    }
    printf("Decimal: %d to binary:%ld\n", n, ret);
}


int main()
{
     int a;
     printf("please input a integer beween 0 to 1023:\n");
     while((scanf("%d", &a))!=EOF)
     {
         DecimaltoBinary(a);
     }
     return 0;
}
