#include<stdio.h>
#include<string.h>

void fun(char c)
{
    if(c >= 'a'&& c <= 'z')
        printf("%c : %c\n", c, c-32);
}

int main()
{
    char c;
    while((scanf("%c", &c)) != EOF)
        fun(c);
    return 0;
}
