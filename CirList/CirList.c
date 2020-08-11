#include "CirList.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void CListInit(CList *c)
{
	c->_pHead = NULL;
}

pNode GetNewNode(CListData data)
{
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
	{
		return NULL;
	}
	strcpy(pNewNode->_data, data);
	pNewNode->_pNext = NULL;
	pNewNode->_pPrev = NULL;
	return pNewNode;
}

void CListPushBack(CList *c, CListData data)
{
	pNode pNewNode = GetNewNode(data);
	if(NULL == c->_pHead)
	{
		c->_pHead = pNewNode;
		c->_pHead->_pNext = c->_pHead;
		c->_pHead->_pPrev = c->_pHead;
	}
	else if(c->_pHead == c->_pHead->_pNext)
	{
		c->_pHead->_pNext = pNewNode;
		c->_pHead->_pPrev = pNewNode;
		pNewNode->_pNext = c->_pHead;
		pNewNode->_pPrev = c->_pHead;
	}
	else
	{
		c->_pHead->_pPrev->_pNext = pNewNode;
		pNewNode->_pPrev = c->_pHead->_pPrev;
		pNewNode->_pNext = c->_pHead;
		c->_pHead->_pPrev = pNewNode;
	}
}

void CListPopBack(CList *c)
{
  if(NULL == c->_pHead)
  {
    return;
  }
	else if(c->_pHead == c->_pHead->_pNext)
	{
		free(c->_pHead);
		c->_pHead = NULL;
	}
	else
	{
		pNode pCur = c->_pHead->_pPrev;
		c->_pHead->_pPrev->_pPrev->_pNext = c->_pHead;
		c->_pHead->_pPrev = c->_pHead->_pPrev->_pPrev;
		free(pCur);
	}
}

void CListPushFront(CList *c, CListData data)
{
	CListPushBack(c, data);
	c->_pHead = c->_pHead->_pPrev;
}

void CListPopFront(CList *c)
{
  if(NULL == c->_pHead)
  {
    return;
  }
	c->_pHead = c->_pHead->_pNext;
	CListPopBack(c);
}

void CListInsert(CList *c, int pos, CListData data)
{
	int count = Size(c) - 1;
	if(pos < 0 | pos > count)
	{
		return;
	}
	pNode pNewNode = GetNewNode(data);
	pNode pCur = c->_pHead;
	count = 0;
	if(0 == pos)
	{
		CListPushFront(c, data);
	}
	else
	{
		while(count != pos)
		{
			count++;
			pCur = pCur->_pNext;
		}
		pNewNode->_pNext = pCur;
		pCur->_pPrev->_pNext = pNewNode;
		pNewNode->_pPrev = pCur->_pPrev;
		pCur->_pPrev = pNewNode;
	} 
}

void CListErase(CList *c, int pos)
{
  if(NULL == c->_pHead)
  {
    return;
  }
	int count = Size(c) - 1;
	if(pos < 0 | pos > count)
	{
		return;
	}
	pNode pCur = c->_pHead;
	count = 0;
	if(0 == pos)
	{
		CListPopFront(c);
	}
	else
	{
		while(count != pos)
		{
			pCur = pCur->_pNext;
			count++;
		}
		pCur->_pPrev->_pNext = pCur->_pNext;
		pCur->_pNext->_pPrev = pCur->_pPrev;
		free(pCur);
	}
}

void CListClear(CList *c)
{
	if(NULL == c->_pHead)
	{
		return;
	}
	c->_pHead->_pNext = NULL;
	c->_pHead->_pPrev = NULL;
	c->_pHead = NULL;
}

void CListSize(CList *c)
{
	if(NULL == c->_pHead)
	{
		printf("size = 0\n");
		return;
	}
	int size = 1;
	pNode pCur = c->_pHead;
	while(pCur->_pNext != c->_pHead)
	{
		size++;
		pCur = pCur->_pNext;
	}
	printf("size = %d\n", size);
}

int Size(CList *c)
{
	int size = 1;
	pNode pCur = c->_pHead;
	while(pCur->_pNext != c->_pHead)
	{
		size++;
		pCur = pCur->_pNext;
	}
	return size;
}

int CListFind(CList *c, CListData data)
{
	pNode pCur = c->_pHead;
	int count = 0;
	if(NULL == c->_pHead)
	{ 
		return -1;
	}
	while(pCur->_data != data)
	{
		pCur = pCur->_pNext;
		count++;
		if(count >= Size(c))
		{
			return -1;
		}
	}
	return count;
}

void Print(CList *c)
{
	pNode pCur = c->_pHead;
	if(NULL == c->_pHead)
	{
		printf("NULL<--->NULL");
	}
	else if(c->_pHead == c->_pHead->_pNext)
	{
		printf("%s<--->%s", c->_pHead->_data, c->_pHead->_data);
	}
	else
	{
		printf("%s<--->", c->_pHead->_data);
		while(pCur->_pNext != c->_pHead)
		{
			pCur = pCur->_pNext;
			printf("%s<--->", pCur->_data);
		}
		printf("%s", c->_pHead->_data);
	}
	printf("\n");
}

void Destroy(CList *c)
{
	c->_pHead = NULL;
}
