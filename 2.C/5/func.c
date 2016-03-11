#include "list.h"

void link_head_insert(pstu *phead,pstu *ptail, int n)//链表头插法
{
    if(*phead == NULL)//没有元素
    {
        pstu pnew = (pstu)malloc(sizeof(stu));
        memset(pnew, 0, sizeof(stu));//结点初始化
        pnew->num = n;
        if(*phead == NULL)
        		{
            *phead = pnew;
            *ptail = pnew;
        }else{
            pnew -> pnext = *phead;
            *phead = pnew;
        }
    }
}



void link_tail_insert(pstu *phead, pstu *ptail, int n)//尾插法
{
	pstu pnew = (pstu)malloc(sizeof(stu));     
	memset(pnew, 0, sizeof(stu));//结点初始化
   pnew->num = n;
	if(*ptail == NULL)
	{
		  *phead = pnew;
        *ptail = pnew;		
	}else{
			(*ptail) -> pnext = pnew;//将我们新增的结点赋值给原有结点的pnext
			*ptail = pnew;//将新结点变为尾部
	}
}



void link_show(pstu phead)//显示链表
{
     pstu pscur;
     pscur = phead;
     while(pscur != NULL)
     {
          printf("%3d", pscur -> num);
          pscur = pscur -> pnext;
     }
     printf("\n");
}
