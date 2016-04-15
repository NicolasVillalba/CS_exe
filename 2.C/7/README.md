1、从键盘任意输出一个4位数x，编程计算x的每一位数字相加之和(忽略整数前的正负号)。例如，输入x为-1234，则由1234分离出其千位1、百位2、十位3、个位4，然后计算1+2+3+4=10，并输出10

2、删除一个字符串中 指定的字串，例如“how are you",删除 "are",则变成 “how  you”。
    void remove(char* main_str,char* sub_str);

3、文件file中有如下内容：
1,2,3,4,5,6,7,8,9,10
将其读出变为一个10个节点的链表，然后将其拆分成两个链表，一个链表全是奇数，一个链表全是偶数
如下：
L1  1,2,3,4,5,6,7,8,9,10
L2  1,3,5,7,9
L3  2,4,6,8,10

typedef struct tag
{
    int m_ival;
    struct tag* pnext;
}Node,*pNode;

void split(pNode L1,pNode L2,pNode L3)


4、实现一个 stack;
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
int top(pStack stack) //返回栈顶元素
void push(pStack stack,int val)//入栈
int empty(pStack stack) //判断栈是否为空
int size(pStack stack) //返回栈中数据的元素个数
