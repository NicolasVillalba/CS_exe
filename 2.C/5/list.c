#include "list.h"


int main()
{
    pstu phead, ptail;
    int num;
    phead = NULL;
    ptail = NULL;
    while(scanf("%d", &num)!= EOF)
    {
       // link_head_insert(&phead, &ptail, num);//头插法
       link_tail_insert(&phead, &ptail, num);
    }
    link_show(phead);
}

