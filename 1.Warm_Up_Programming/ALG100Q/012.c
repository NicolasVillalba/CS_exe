#include<stdio.h>

int main()
{
    int cnt = 0;
    int k = 0;
    for(int i = 101; i <= 200; i++)
    {
        int k = 1;
        for(int j = 2; j < i; j++ )
        {
            if( i%j == 0 ) k = 0;
        }
        if(k == 1)
        {
            printf("%d\n", i);
            cnt++;
        }
    }
    printf("There are %d primers.\n", cnt);
    return 0;
}
