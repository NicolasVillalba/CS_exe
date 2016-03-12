//将一个链表拆分(将链表奇数位置上的节点构成一个链表,偶数位置上的节点构成另一
//个链表)
//例如:L:1 -> 2 -> 3 ->4 ->5 ->6 ->7 ->8 ->9 -> NULL
//L1: 1 ->3 ->5 ->7 ->9 -> NULL ;
//L2: 2 ->4 ->6 ->8 -> NULL
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node; 


Node phead = NULL, ptail = NULL;
Node phead1 = NULL, ptail1 = NULL;
Node phead2 = NULL, ptail2 = NULL;


void link_tail_insert(Node *phead, Node *ptail, int n)
{
	Node pnew = (Node)malloc(sizeof(nod));
	memset(pnew, 0, sizeof(nod));
	pnew->num = n;
	if(*ptail == NULL){
		*phead = pnew;
		*ptail = pnew;
	}else{
		(*ptail)->pnext = pnew;
		*ptail = pnew;
	}
}

void link_desprate()
{
	int cnt = 1;
	Node pscur = phead;
	while(pscur != NULL)
	{
		if(cnt%2 == 1) link_tail_insert(&phead1, &ptail1, pscur->num);
		else link_tail_insert(&phead2, &ptail2, pscur->num);
		pscur = pscur->pnext;
		cnt++;
	}
}


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



int main()
{
	int num;
	while((scanf("%d", &num)))
	{
		if(num == -1){
			link_show(phead);
			break;
		}else link_tail_insert(&phead, &ptail, num);
	}
	link_desprate();
	link_show(phead1);
	link_show(phead2);
	return 0;
}
