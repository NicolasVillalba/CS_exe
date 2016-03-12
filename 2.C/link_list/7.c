#include<stdio.h>
#include<stdlib.h>
#include<string.h>



///将一个链表逆置。
//如: 1->2 ->3 ->4 ->5 ->NULL, 输出: 5 -> 4 -> 3 ->2 ->1 -> NULL ;
typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;

Node phead1 = NULL, ptail1 = NULL;

void link_head_insert(Node *phead, Node *ptail, int n)
{
		Node pnew = (Node)malloc(sizeof(nod));
		memset(pnew, 0, sizeof(nod));
		pnew->num = n;//以上为初始化需要插入的结点
		if(*phead == NULL)
		{
			*phead = pnew;
			*ptail = pnew;			
		}else{
			pnew -> pnext = *phead;
			*phead = pnew;
		}
}


void link_reverse(Node *phead, Node *ptail)
{
	while(phead1 != NULL)
	{
		link_head_insert(phead, ptail, phead1->num);
		phead1 = phead1->pnext;
	}	
}


void link_tail_insert(Node *phead, Node *ptail, int n)
{
	Node pnew = (Node)malloc(sizeof(nod));
	memset(pnew, 0, sizeof(nod));
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



void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%d ", pscur->num);
		pscur = pscur->pnext;
	}
	printf("\n");
}



int main()
{
	Node phead = NULL, ptail = NULL;
	
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead1);
			break;
		}else link_tail_insert(&phead1, &ptail1, num);
	}
	link_reverse(&phead, &ptail);
	printf("After reverse:\n");
	link_show(phead);
	return 0;
}

