#include<stdio.h>

void fun(int a[], int p)
{
    int s[p+1];
    int n = 0;
    for(int i = 0; i <= p; i++)
        s[n++] = a[i];
    int k = 0;
    for(int i = n; a[i] != '\0'; i++)
        a[k++] = a[i];
    int m = 0;
    for(int i = k; a[i] !='\0'&&s[m] != '\0'; i++)
        a[i] = s[m++];
}

int main()
{
     int a[] = {1,2,3,4,5,6,7,8,9,10};
     int p = 3;
     fun(a, p);
     for(int i = 0; a[i] != '\0'; i++)
         printf("%d ", a[i]);
     printf("\n");
     return 0;
}
