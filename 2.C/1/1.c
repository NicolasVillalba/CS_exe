//打印九九乘法表
#include <stdio.h>

int main()
{
    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            printf("%d*%d=%-3d",j, i, i*j);
        }
        printf("\n");
    }
    return 0;

}
