//删除单链表中重复的元素
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


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


/*void link_tail_insert(Node *phead, Node *ptail, int n)*/
/*{*/
/*	Node pnew = (Node)malloc(sizeof(nod));*/
/*	memset(pnew, 0, sizeof(nod));*/
/*	pnew->num = n;*/
/*	if(*ptail == NULL)*/
/*	{*/
/*		*ptail = pnew;*/
/*		*phead = pnew;*/
/*	}else{*/
/*		(*ptail)->pnext = pnew;*/
/*		*ptail = pnew;*/
/*	}*/
/*}*/




/*void link_delete(Node *phead, Node *ptail, int n)*/
/*{*/
/*	Node ppre = NULL;*/
/*	Node pscur;*/
/*	pscur = *phead;*/
/*	while(pscur != NULL)*/
/*	{*/
/*		if(pscur -> num == n){*/
/*		if(pscur == NULL)*/
/*		{*/
/*			*phead = pscur -> pnext;*/
/*		}else{*/
/*			ppre -> pnext = pscur -> pnext;*/
/*		}*/
/*		free(pscur);*/
/*		pscur = NULL;*/
/*		return;*/
/*		}*/
/*	ppre = pscur;*/
/*	pscur = pscur -> pnext;*/
/*	}*/
/*}*/





/*void link_delete_union(Node *phead, Node *ptail)*/
/*{*/
/*	Node *pscur = phead;	*/
/*	if(pscur == NULL){*/
/*		printf("The Node is empty.\n");*/
/*		return;*/
/*	}*/
/*	while(pscur != NULL)*/
/*	{*/
/*		Node *pscur1 = (pscur)-> pnext;*/
/*		while(*pscur1 != NULL)*/
/*		{*/
/*			if((*pscur)->num == (*pscur1)->num) link_delete(phead, ptail, (*pscur1)->num);*/
/*			else *pscur1 = (*pscur1)->pnext;*/
/*		}*/
/*		*pscur = (*pscur)->pnext;*/
/*	}*/
/*}*/



void link_sort_insert_withoutUnion(Node *phead, Node *ptail, int n)
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
			if(pcur->num == n) return;
			if(pcur -> num > n)
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
	Node phead = NULL, ptail = NULL;
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			break;
		}else link_sort_insert_withoutUnion(&phead, &ptail, num);
	}
	return 0;
}
