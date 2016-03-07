#include<stdio.h>

int countWord(const char *s)
{
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++) 
        if(s[i] == ' ')cnt++;
    if(s[0] == ' ') cnt--;
    return cnt;
}

int main()
{
     char s[] = " hello world how are you ";
     int cnt = countWord(s);
     printf("there is %d letters total.\n", cnt);
     return 0;
}
