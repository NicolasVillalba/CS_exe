#include<stdio.h>

int main()
{
    float sn=100.0,hn=sn/2;
    int n;
    for(n=2;n<=10;n++)
    {
        sn=sn+2*hn;/*第 n 次落地时共经过的米数*/
        hn=hn/2; /*第 n 次反跳高度*/

    }
    printf("the total of road is %f\n",sn);
    printf("the tenth is %f meter\n",hn);
    return 0;
}
