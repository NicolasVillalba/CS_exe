#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用尾插法建立链表。
typedef struct student{
	int num;
	struct student *pnext;
}stu, *pstu;

void link_tail_insert(pstu *phead, pstu *ptail, int n)
{
	pstu pnew = (pstu)malloc(sizeof(stu));
	memset(pnew, 0, sizeof(stu));
	pnew->num = n;
	if(*ptail == NULL)
	{
		*phead = pnew;
		*ptail = pnew;
	}else{
		(*ptail) -> pnext = pnew;
		*ptail = pnew;
	}
}



void link_show(pstu phead)
{
	pstu pscur;
	pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur -> num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


int main()
{
	pstu phead, ptail;
	int num;
	phead = NULL;
 	ptail = NULL;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			return 0;
		}else link_tail_insert(&phead, &ptail, num);
	}
}

