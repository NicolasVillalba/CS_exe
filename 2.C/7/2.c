#include<stdio.h>
#include<string.h>

void removes(char* main_str, char* sub_str)
{
    int i, j;
    int cntpos = 0;
    for(i = 0, j = 0; main_str[i] != '\0';i++)
    {
        if(main_str[i] == sub_str[j])
        {
            if(j == 0) cntpos = i;
            j++;
            if(j == strlen(sub_str)) break;
        }else{
            j= 0;
        }
    }
    printf("cntpos= %d,j = %d\n", cntpos,j);
    for(i = cntpos; i <= cntpos + j; i++)
        main_str[i] = main_str[i + j];
    main_str[i] = '\0';
}


int main()
{
     char main_str[20] = "how are you";
     char sub_str[10] = "are";
     removes(main_str, sub_str);
     printf("%s\n", main_str);
     return 0;
}
