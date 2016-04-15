#include<stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(a < 0) a *= -1;

    int sum;
    while(a!=0)
    {
        sum += a%10;
        a /= 10;
    }
    printf("%d\n", sum);
    return 0;
}
