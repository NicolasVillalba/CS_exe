#include<stdio.h>
#include<string.h>


int count(char *s, char *str)
{
    int cnt = 0;
    for(int i = 0; i < strlen(s) - 1; i++)
    {
        if(s[i] == str[0] && s[i+1] == str[1]) cnt++;
    }
    return cnt;
}

int main()
{
    char s[] = "askjhkhkjadsybhwaskhjkhwas";
    char str[] = "as";
    int n = count(s, str);
    printf("%d\n", n);
    return 0;
}
