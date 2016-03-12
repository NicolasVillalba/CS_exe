#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
	int num;
	struct node *pnext;
}nod, *Node;


void link_show(Node phead)
{
	Node pscur = phead;
	while(pscur != NULL)
	{
		printf("%d ", pscur-> num);
		pscur = pscur->pnext;
	}
	printf("\n");
}


void link_delete(Node *phead, Node *ptail, int n)
{
	Node ppre = NULL;
	Node pscur;
	if(*phead == NULL){
		printf("The link is empty\n");
	}else{
		pscur = *phead;
		while(pscur != NULL)
		{
			if(pscur -> num == n){
			if(pscur == NULL)
			{
				*phead = pscur -> pnext;
			}else{
				ppre -> pnext = pscur -> pnext;
			}
			free(pscur);
			pscur = NULL;
			return;
			}
		ppre = pscur;
		pscur = pscur -> pnext;
		}
		printf("This Node doesn't exist!\n'");
	}
}



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
			int n = 0;
			printf("Please input the number you want to remove in the node:\n");
			scanf("%d", &n);
			link_delete(&phead, &ptail, n);
			printf("after delete\n");
			link_show(phead);
			return 0;
		}else link_head_insert(&phead, &ptail, num);
	}
}



