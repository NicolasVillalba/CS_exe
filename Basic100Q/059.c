#include<stdio.h>
#include<string.h>
#define M 3
#define N 10

void fun(char s[M][N], char *t)
{
    int cnt = 0;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < strlen(s[i]); j++)
            t[cnt++] = s[i][j];
    t[cnt] = '\0';
}

int main()
{
    char s[M][N] = {
         "AAAA",
         "BBBBBBB",
         "CC"
    };
    char t[M*N];
    fun(s, t);
    printf("%s\n", t);
    return 0;
}

