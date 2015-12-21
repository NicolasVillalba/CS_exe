#include<stdio.h>
#include<string.h>

int fun(char *str)
{
    int s = 1;
    int res = 0;
    if(str[0] == '-')
    {
        s = -1;
        for(int i = 1; i < strlen(str); i++)
        {
            res = res * 10 + (str[i] - '0');
        }
        res *= s;
        return res;
    }else if(str[0] == '+'){
         for(int i = 1; i < strlen(str); i++)
         {
             res = res * 10 + (str[i] - '0');
         }
         return res;
    }else{
        for(int i = 0; i < strlen(str); i++)
            res = res * 10 + (str[i] - '0');
        return res;
    }
}


int main()
{
     char s1[] = "12345";
     int n1 = fun(s1);
     printf("string %s is number %d\n", s1, n1);
     char s2[] = "-12768";
     int n2 = fun(s2);
     printf("string %s is number %d\n", s2, n2);
     char s3[] = "+12897";
     int n3 = fun(s3);
     printf("string %s is number %d\n", s3, n3);
     return 0;
}
