#include<stdio.h>

int main()
{
    int cnt = 0;
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 1; k <= 4; k++)
            {
                if((i!=k && j != i) && j != k)
                {
                    printf("%d%d%d\n", i, j, k);
                    cnt++;
                }
            }
        }
    }
    printf("%d\n", cnt);
}
