#include<stdio.h>


/*void fun(char c)*/
/*{*/
/*    int alp = 0, num = 0, oth = 0;*/
/*    if((c >= 'a'&& c <= 'z') || (c >= 'A' && c <= 'Z')) alp++;*/
/*    else if(c >= '0' && c <= '9') num++;*/
/*    else oth++;*/

/*    int max = (alp > num )?((alp > oth)?alp:oth):((num > oth)?num:oth);*/
/*    for(int i = max + 1; i > 0; i--)*/
/*    {*/
/*        if((alp + 1) == i) printf("  %d     ",alp);*/
/*        else if(alp > i) printf("*****   ");*/
/*        else printf("        ");*/

/*        if((num + 1) == i) printf("  %d  ", num);*/
/*        else if(num > i) printf("*****   ");*/
/*        else printf("        ");*/

/*        if((oth + 1) == i) printf("  %d\n",oth);*/
/*        else if(oth > i) printf("*****\n");*/
/*        else printf("\n");*/
/*    }*/
/*    printf(" alp     num       oth\n");*/
/*}*/

int main()
{
    char c;
    int alp = 0, num = 0, oth = 0;
    printf("please input char and '~' is the char of the stop\n");
    while(((scanf("%c", &c)) != EOF) && c != '~')
        {
        if((c >= 'a'&& c <= 'z') || (c >= 'A' && c <= 'Z')) alp++;
        else if(c >= '0' && c <= '9') num++;
        else oth++;
        }
  int max = (alp > num )?((alp > oth)?alp:oth):((num > oth)?num:oth);
  for(int i = max + 1; i > 0; i--)
      {
        if((alp + 1) == i) printf("  %d     ",alp);
        else if(alp > i) printf("*****   ");
        else printf("        ");

        if((num + 1) == i) printf("  %d     ", num);
        else if(num > i) printf("*****   ");
        else printf("        ");

        if((oth + 1) == i) printf("  %d\n",oth);
        else if(oth > i) printf("*****\n");
        else printf("\n");
      }
    printf(" alp     num      oth\n");
    return 0;
}
