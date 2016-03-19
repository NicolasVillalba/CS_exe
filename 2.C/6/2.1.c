//带头节点的单链表，生成链表，遍历链表，删除链表最大节点
//链表的考点在于结构体，然后是指针

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//利用结构体定义一个链表结点
typedef struct node{
    int num;
    struct node *pnext;
}nod, *Node;



void link_head_insert(Node *phead,Node *ptail, int n)//头插法，就是将需要增加的数据加从链表的头部插入
{
        Node pnew = (Node)malloc(sizeof(nod));
        memset(pnew, 0, sizeof(nod));//结点初始化
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



void link_tail_insert(Node *phead, Node *ptail, int n)//尾插法，将需要插入链表的数据插入链表的尾部
{
	Node pnew = (Node)malloc(sizeof(nod));     
	memset(pnew, 0, sizeof(nod));//结点初始化
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



void link_sort_insert(Node *phead, Node *ptail, int n)//有序插入，按照插入数字的大小插入链表，就是最后得到的链表是从小到大排列的
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




//删除
//空的时候
//不为空的时候，开始遍历
void link_delete(Node *phead, Node *ptail, int n)//删除链表中的的数据n
{
	Node ppre = NULL;
	Node pcur;
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




int link_search(Node phead, int n)//查找链表
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



void link_show(Node phead)//显示链表
{
     Node pscur;
     pscur = phead;
     while(pscur != NULL)
     {
          printf("%3d", pscur -> num);
          pscur = pscur -> pnext;
     }
     printf("\n");
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////
//以上所有的都是定义函数，以下为主函数
int main()
{
    Node phead, ptail;
    int num;
    phead = NULL;
    ptail = NULL;
    //有序创建链表
    printf("请输入5个数字创建链表：\n");
    for(int i = 0; i < 5; i++)
    {
        int n;
        scanf("%d", &n);
        link_sort_insert(&phead, &ptail, n);
    }
    
    //调用显示链表函数
    link_show(phead);
    
    int m;
    printf("请输入你想从链表删除的数：\n");
    scanf("%d", &m);
    link_delete(&phead, &ptail, m);
    printf("删除之后的链表为:\n");
    
    //调用显示链表函数
    link_show(phead);
    
    return 0;
}
