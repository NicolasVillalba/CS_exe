#include "list.h"

void link_head_insert(pstu *phead,pstu *ptail, int n)//头插法
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



void link_sort_insert(pstu *phead, pstu *ptail, int n)
{
	pstu pcur;
	pstu ppre;
	pstu pnew = (pstu)malloc(sizeof(stu));     
	memset(pnew, 0, sizeof(stu));//结点初始化
    pnew->num = n;
	if(*phead == NULL)//判断为空
	{
		*phead = pnew;
		*ptail = pnew;
	}else if((*phead)->num > n){//插入到头部
		pnew -> pnext = *phead;
		*phead = pnew;
	}else if((*ptail)->num < n){//插入到尾部
		(*ptail) -> pnext = pnew;
		(*ptail) = pnew;
	}else{//插入中间
		pcur = *phead;
		while(pcur != NULL)
		{
			
			if(pcur -> num >n)
			{
				ppre -> pnext = pnew;
				pnew -> pnext = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur -> pnext;
		}
	}
}


//删除
//空的时候
//不为空的时候，开始遍历
void link_delete(pstu *phead, pstu *ptail, int n)
{
	pstu ppre = NULL;
	pstu pcur;
	if(*phead == NULL) {
		printf("the link is empty");	
	}else{
		pcur = *phead;
		while(pcur != NULL)
		{
			if(pcur -> num ==n)
			{
				if(ppre ==NULL)
				{
					*phead = pcur -> pnext;
				}else{
					ppre -> pnext = pcur -> pnext;
				}
				free(pcur);
				pcur = NULL;
				return;
			}
				ppre = pcur;
				pcur = pcur -> pnext;
		}
		printf("THis Node doesn't exist!\n'");
	}
}




int link_search(pstu phead, int n)
{
	while(phead != NULL)
	{
		if(phead -> num == n)
		{
			return 1;
		}
	}
	return 0;
}



int link_modify(pstu phead, int old, int n)
{
	int flag = 0;
	while(phead != NULL)
	{
		if(phead -> num == old)
		{
			phead -> num = n;
			flag++;	
		}
		phead = phead -> pnext;
	}
	return flag;
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
