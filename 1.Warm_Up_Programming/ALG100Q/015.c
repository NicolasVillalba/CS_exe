#include<stdio.h>

int main()
{
    int score;
    printf("please input the score:\n");
    scanf("%d", &score);
    if( score >= 90) printf("A\n");
    else if( score < 60 ) printf("C\n");
    else printf("B\n");
    return 0;
}
