#ifndef _CIRLIST_H_
#define _CIRLIST_H_

typedef char* CListData;

typedef struct CListNode
{
	char _data[1024];
	struct CListNode* _pNext;
	struct CListNode* _pPrev;
}Node,*pNode;

typedef struct CList
{
	pNode _pHead;
}CList;

void CListInit(CList *c);
void CListPushBack(CList *c, CListData data);
void CListPopBack(CList *c);
void CListPushFront(CList *c, CListData data);
void CListPopFront(CList *c);
void CListInsert(CList *c, int pos, CListData data);
void CListErase(CList *c, int pos);
void CListClear(CList *c);
void CListSize(CList *c);
int Size(CList *c);
pNode BuyNewNode(char* data);
int CListFind(CList *c, char* data);
void Print(CList *c);
void Destroy(CList *c);

#endif
