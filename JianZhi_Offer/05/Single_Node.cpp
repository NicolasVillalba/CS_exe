 ///
 /// @file    Single_Node.cpp
 /// @author  AverageJoeWang(AverageJoeWang@gmail.com)
 ///
 
#include <iostream>
using std::cout;
using std::endl;

struct ListNode
{
	int m_nValue;
	ListNode * m_pNext;
};

void AddToTail(ListNode ** pHead, int value)//插入尾部
{
	ListNode * pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;
	if(*pHead == NULL)
	{
		*pHead = pNew;
	}else
	{
		ListNode * pNode = *pHead;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode ** pHead, int value)
{
	if(pHead == NULL || *pHead == NULL)
		return;
	ListNode * pToBeDeleted = NULL;
	if((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}else
	{
		ListNode * pNode = *pHead;
		while(pNode->m_pNext != NULL&& pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if(pNode->m_pNext != NULL&& pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if(pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeleted = NULL;
	}
}



