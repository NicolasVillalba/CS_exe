#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tag{
    int m_ival;
    struct tag* pnext;
}Node, *pNode;

void link_tail_insert(pNode *phead, pNode *ptail, int n)//尾插法
{
	pNode pnew = (pNode)malloc(sizeof(Node));     
	memset(pnew, 0, sizeof(Node));//结点初始化
    pnew->m_ival = n;
	if(*ptail == NULL)
	{
		  *phead = pnew; 
        *ptail = pnew;		
	}else{
			(*ptail) -> pnext = pnew;//将我们新增的结点赋值给原有结点的pnext
			*ptail = pnew;//将新结点变为尾部
	}
}


void link_show(pNode phead)//显示链表
{
     pNode pscur;
     pscur = phead;
     while(pscur != NULL)
     {
          printf("%3d", pscur -> m_ival);
          pscur = pscur -> pnext;
     }
     printf("\n");
}


int main()
{
    pNode phead1, ptail1;
    pNode phead2, ptail2;//偶数
    pNode phead3, ptail3;//奇数
    FILE *fp = fopen("file", "r");
    
    char buf[] = {1,2,3,4,5,6,7,8,9,10};
    fclose(fp);
    int i = 0;
    for(i; i < strlen(buf); i++)
    {
        if(buf[i]%2 == 0)
        {
            link_tail_insert(&phead1, &ptail1, buf[i] - '0');
            link_tail_insert(&phead2, &ptail2, buf[i] - '0');
        }else{
            link_tail_insert(&phead1, &ptail1, buf[i] - '0');
            link_tail_insert(&phead3, &ptail3, buf[i] - '0');
        }
    }
    
    printf("the first list is\n");
    link_show(phead1);
    printf("the second list is\n");
    link_show(phead2);
    printf("the third list is\n");
    link_show(phead3);
    return 0;
}
