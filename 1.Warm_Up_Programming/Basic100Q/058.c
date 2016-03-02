#include<stdio.h>
#include<math.h>

int fun(int n)
{
    int sum = 0;
    for(int i = 7; i < n; i++)
        if(i % 3 == 0 && i % 7 == 0) sum += i;
    return sqrt(sum);
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int s = fun(n);
    printf("%d\n",s);
    return 0;
}
