 ///
 /// @file    Print.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

struct ListNode
{
	int m_nKey;
	ListNode * m_pNext;
};

void PrintListNode(ListNode * pHead)
{
	stack<ListNode> nodes;

	ListNode *pNew = pHead;
	while(pNew != NULL)
	{
		nodes.push(pNew);
		pNew = pNew->m_pNext;
	}

	while(!nodes.empty())
	{
		cout <<(nodes.top())->m_nValue << endl;
		nodes.pop();
	}
}


int main()
{

	return 0;
}
