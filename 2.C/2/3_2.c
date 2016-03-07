#include<stdio.h>
#include<math.h>

int main()
{
    int a;
    while((scanf("%d", &a)) != EOF)
    {
        int n = a;
        int ret = 0;
        int cnt = 0;
        while(a != 0)
        {
            int tmp = a%10;
            ret += tmp * pow(2, cnt);
            cnt++;
            a /= 10;
        }
        printf("%d  : %d\n", n, ret);
    }
    return 0;
}
