#include<stdio.h>
#include<string.h>

void fun(char *tt, int pp[])
{
    memset(pp, 0, sizeof(int) * 26);//清零操作
    for(int i = 0; tt[i] != '\n'; i++)
        if(tt[i] <='z' && tt[i] >='a') ++pp[tt[i] - 'a'];//-'a'操作是用于归零操作;
}

int main()
{
    char *str = "helloeveryoneiamsogladtoseeyou";
    int count[26];
    fun(str, count);
    for(int i = 0; i < 26; ++i) printf("%c: %d\n", 'a' + i, count[i]);
    return 0;
}
