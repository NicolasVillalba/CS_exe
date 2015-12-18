#include<stdio.h>
#include<string.h>

void fun(char *str)
{
    int len = strlen(str);
    for(int i = 1; i < len -2; ++i)
    {
        for(int j = 1; j < len - 1 - i; ++j)
        {
            if(str[j] < str[j+1])
            {
                char tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;
            }
        }
    }
}

int main()
{
    char str[] = "wanglifeilosvechenshuhuanSKJH";
    fun(str);
    printf("the result is %s\n", str);
    return 0;
}
