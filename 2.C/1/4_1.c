#include<stdio.h>

int main()
{
    char a[10] = "0123456789";
    char b[2] = "46";
    int i = 0, j =0;
    while(a[i] != '\0' && b[j] != '\0')
    {
        if(a[i] < b[j]) i++;
        else if(a[i] == b[j]) {
            printf("%c ", a[i]);
            i++;
            j++;
        }
        else j++;
    }
    printf("\n");
    return 0;
}
