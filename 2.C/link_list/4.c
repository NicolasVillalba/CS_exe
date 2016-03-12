#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//用有序插入建立链表。
typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;



void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%3d", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


void link_sort_insert(Node *phead, Node *ptail, int n)
{
	Node pcur;
	Node ppre;
	Node pnew = (Node)malloc(sizeof(nod));     
	memset(pnew, 0, sizeof(nod));//结点初始化
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


int main()
{
	Node phead, ptail;
	int num;
	phead = NULL;
 	ptail = NULL;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			return 0;
		}else link_sort_insert(&phead, &ptail, num);
	}
}
