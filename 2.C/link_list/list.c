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
       //link_tail_insert(&phead, &ptail, num);
		//有序插入
		link_sort_insert(&phead, &ptail, num);
    }
	link_show(phead);
	int n;
	scanf("%d%d", &num, &n);
	if(link_modify(phead, num, n)) printf("success!\n");
	else printf("failed\n");
	//if(link_search(phead, num)) printf("The noe is exist\n");
	//else printf("The node doesn't exist\n'");
	
//	link_delete(&phead, &ptail, num);
   link_show(phead);
	
}

