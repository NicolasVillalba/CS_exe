#include<stdio.h>
#include<string.h>

void deleteChar(char *s, char *r, char ch)
{
    int n = 0;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == ch) continue;
        else r[n++] = s[i];
    r[n] = '\0';
}

int main()
{
    char s[] = "sdkjfhaksdyoHHSSASDCWssswwwwlfchs";
    char r[100];
    memset(r, '0',sizeof(char)*100);
    deleteChar(s, r, 'S');
    printf("%s\n", r);
    return 0;
}
