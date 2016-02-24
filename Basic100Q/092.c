#include<stdio.h>
#include<math.h>

double fun(int m)
{
    double sum = 0.0;
    for(int i = 1; i <= m; i++)
        sum += log(i);
    double s = pow(sum, 0.5);
    return s;
}

int main()
{
     printf("%0.6lf\n",fun(20));
     return 0;
}
