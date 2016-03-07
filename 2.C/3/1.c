#include<stdio.h>

char *mystrcpy(char *s,const char *t, int n)
{
    int i;
    for(i = 0; i < n && t[i] != '\0'; i++)
        s[i] = t[i];
    for(; i < n; i++)
        s[i] = '\0';
    return s;
}

int mystrcmp(const char *s, const char *t)
{
    for(int i = 0; s[i] != '\0' && t[i] != '\0'; i++)
    {
        if(s[i] > t[i]) return 1;
        else if(s[i] < t[i]) return -1;
    }
    return 0;
}

char *mystrcat(char *s, const char *t, int n)
{
    int m = 0;
    for(;s[m] != '\0'; m++);

    int i;
    for(i = 0; i < n && t[i] != '\0'; i++)
        s[m + i] = t[i];
    s[m + i] = '\0';

    return s;
}


int mystrlen(const char *s)
{
    int cnt = 0;
    while(s[cnt] != '\0') cnt++;
    return (cnt + 1);
}


int main()
{
     printf("test mystrcpy:\n");
     char s1[30] = "";
     char t1[22] = "testMystrcpyisSuccess";
     mystrcpy(s1, t1, 22);
     printf("%s\n", s1);


     printf("test mystrcmp:\n");
     char s2[4] = "abc";
     char t2[4] = "abd";
     int n = mystrcmp(s2, t2);
     if(n == 0) printf("The are equal.\n");
     else if(n == 1) printf("s2 is more than t2.\n");
     else printf("s2 is less than t2.\n");

     printf("test mystrcat:\n");
     char s3[30] = "My name is ";
     char t3[10] = "Wanglifei";
     mystrcat(s3, t3, 10);
     printf("%s\n", s3);

     printf("test mystrlen:\n");
     char s4[] = "theismylastfunction";
     int cnt = mystrlen(s4);
     printf("s4 have %d letters.\n", cnt);
     return 0;
}

