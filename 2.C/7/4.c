#include<stdio.h>
#include<string.h>

typedef struct tag
{
    int m_ival;
    struct tag* pnext;
}Node,*pNode;

typedef struct tagstack
{
    pNode m_head;
    int m_size;
}Stack,*pStack;

void pop(pStack stack) //出栈
{
    if(stack->m_size == 0) return;
    if(stack->m_size == 1)
    {
        stack->m_head = NULL;
        m_size =0;
    }else{
        stack->m_head = stack->m_head->pnext;
        m_size--;
    }
}

int top(pStack stack) //返回栈顶元素
{
    if(stack->m_size == 0) return -1;
    else return stack->m_head->m_ival;
}

void push(pStack stack,int val)//入栈
{
    pNode pnew = (pNode)malloc(sizeof(Node));
    memset(pnew, 0, sizeof(Node));
    pnew->m_ival = val;
    stack->m_head->pnext = pnew;
    stack->m_head = pnew;
}

int empty(pStack stack) //判断栈是否为空
{
    if(stack->m_size == 0) return 0;
    else return -1;
}

int size(pStack stack) //返回栈中数据的元素个数
{
    return stack->m_size;
}

int main()
{
    
}
