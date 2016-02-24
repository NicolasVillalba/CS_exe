#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void fun(double x)
{
    double cur = 1, last = 0;
    double factorial = 1, power = 1, numerator = 1;
    for(int i = 1; fabs(cur - last) >= 0.000001; ++i)
    {
        last = cur;
        factorial *= i;
        numerator *= (0.5 - i + 1);
        power *= x;
        cur += numerator * power / factorial;
    }
    printf("%0.6f\n", cur);
}

int main()
{
     fun(0.21);
     return 0;
}
