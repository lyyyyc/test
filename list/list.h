#pragma once

typedef int SDataType;

typedef struct SListNode{
  SDataType _data;
  struct SListNode *_pNext;
}Node, *PNode;

typedef struct{
  PNode _pHead;
}SList;

void SListInit(SList *s);
void SlistPushBack(SList *s, SDataType data);
void SListPopBack(SList *s);
void SListPushFront(SList *s, SDataType data);
void SListPopFront(SList *s);
void SListInsert(PNode pos, SDataType data);
void SListErase(SList *s, PNode pos);
PNode SListFind(SList *s, SDataType data);
int SListSize(SList *s);
void SListClear(SList *s);
void SListDestroy(SList *s);
void Test();
