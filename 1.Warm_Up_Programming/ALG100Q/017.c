#include<stdio.h>

int main()
{
    char c;
    int letter = 0, space = 0, digit = 0, other = 0;
    printf("please input some charscters:\n");
    while((c = getchar()) != '\n');
    {
        if( c >= 'a' && c <= 'z' || c >= 'A'&& c <= 'Z')
            letter++;
        else if(c == ' ') space++;
        else if( c >= '0' && c <= '9' ) digit++;
        else other++;
    }
    printf("char = %d\nspace=%d\ndigit=%d\nother=%d\n",letter, space, digit, other);
    return 0;
}
