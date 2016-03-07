#include<stdio.h>
#define n 10
#define m 8
#define k 5

int main()
{
    char a[n] = "0234789561";
    char b[m] = "09834512";
    char c[k] = "29735";
    for(int i = 0; a[i] != '\0'; i++)
    {
        for(int j = 0; b[j] != '\0'; j++)
        {
             if(a[i] == b[j])
             {
                 for(int x = 0; c[x] != '\0'; x++)
                 {
                      if(a[i] == c[x])
                      {
                          printf("%c ", c[x]);
                          break;
                      }
                 }
             }
        }
    }
    printf("\n");
    return 0;
}
