#include<stdio.h>
#include<math.h>

double fun()
{
    double x1 = 0.0;
    double x0 = 1.0;
    for(int i = 0;; i++)
    {
        if(fabs(x0 - x1) >= 0.000001)
        {
            x0 = x1;
            x1 = cos(x0);
        }else return x1;
    }
}

int main()
{
    double s;
    s = fun();
    printf("root = %lf\n", s);
    return 0;
}
