#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


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



void link_findNode(Node phead)
{
	Node pscur1 = phead;
	Node pscur2 = phead;
	for(int i = 0; i < 4; i++)
	{
		if(pscur2 == NULL) 
		{
			printf("The Node is less than four nodes.\n"); 	
			return;
		}
		pscur2 = pscur2->pnext;
	}
	while(pscur2 != NULL)
	{
		pscur1 = pscur1 -> pnext;
		pscur2 = pscur2-> pnext;
	}
	printf("The Node is %d\n", pscur1->num);
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
			link_show(phead);
			break;
		}else link_tail_insert(&phead, &ptail, num);
	}
	link_findNode(phead);
	return 0;
}
