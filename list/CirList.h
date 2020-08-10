#pragma once 

typedef char* CListData;

typedef struct CListNode
{
  CListData _data;
  struct CListNode* _pNext;
  struct CListNode* _pPrev;
}Node,*pNode;

typedef struct CList
{
  pNode _pHead;
}CList;

int Menu();
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
pNode BuyNewNode(CListData data);
int CListFind(CList *c, CListData data);
//void CListSort(CList *c);
void Print(CList *c);
int AddNode();
int DelNode();
void Destroy(CList *c);
