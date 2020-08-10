#include "list.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void SListInit(SList *s){
  assert(s);
  s->_pHead = NULL;
}

PNode BuyListNode(SDataType data){
  PNode pNewNode = (PNode)malloc(sizeof(Node));
  if(pNewNode == NULL){
    assert(0);
    return NULL;
  }
  pNewNode->_data = data;
  pNewNode->_pNext = NULL;
  return pNewNode;
}

void SListPushBack(SList *s, SDataType data){
  assert(s);
  PNode pNewNode = BuyListNode(data);
  if(s->_pHead == NULL){
    s->_pHead = pNewNode;
  }
  else{
    PNode pCur = s->_pHead;
    while(pCur->_pNext != NULL){
      pCur = pCur->_pNext;
    }
    pCur->_pNext = pNewNode;
  }
}

void SListPopBack(SList *s){
  assert(s);
  if(s->_pHead == NULL){
    return;
  }
  else if(s->_pHead->_pNext == NULL)
  {
    free(s->_pHead);
    s->_pHead = NULL;
  }
  else{
    PNode pPre = NULL;
    PNode pCur = s->_pHead;
    while(pCur->_pNext){
      pPre = pCur;
      pCur = pCur->_pNext;
    }
    free(pCur);
    pPre->_pNext = NULL;
  }
}

void SListPushFront(SList *s, SDataType data){
  assert(s);
  PNode pNewNode = BuyListNode(data);
  if(s->_pHead == NULL){
    s->_pHead = pNewNode;
  }
  else{
    pNewNode->_pNext = s->_pHead;
    s->_pHead = pNewNode;
  }
}

void SListPopFront(SList *s){
  assert(s);
  if(s->_pHead == NULL){
    return;
  }
  else if(s->_pHead->_pNext == NULL)
  {
    free(s->_pHead);
    s->_pHead = NULL;
  }
  else{
    PNode pCur = s->_pHead;
    s->_pHead = s->_pHead->_pNext;
    free(pCur);
  }
}

void SListInsert(PNode pos, SDataType data){
  if(pos == NULL){
    return;
  }
  else{
    PNode pNewNode = BuyListNode(data);
    pNewNode->_pNext = pos->_pNext;
    pos->_pNext = pNewNode;
  }
}

void SListErase(SList *s, PNode pos){
  assert(s);
  if(pos == NULL || s->_pHead == NULL){
    return;
  }
  else if(pos == s->_pHead){
    s->_pHead = pos->_pNext;
  }
  else{
    PNode pPre = s->_pHead;
    while(pPre && pPre->_pNext != pos){
      pPre = pPre->_pNext;
    }
    if(pPre){
      pPre->_pNext = pos->_pNext;
    }
  }
  free(pos);
}

PNode SListFind(SList *s, SDataType data){
  assert(s);
  PNode pCur = s->_pHead;
  while(pCur){
    if(pCur->_data == data){
      return pCur;
    }
    else{
      pCur = pCur->_pNext;
    }
  }
  return NULL;
}

int SListSize(SList *s){
  assert(s);
  PNode pCur = s->_pHead;
  size_t count = 0;
  while(pCur){
    count++;
    pCur = pCur->_pNext;
  }
  return count;
}

void SListClear(SList *s){
  assert(s);
  if(s->_pHead == NULL){
    return;
  }
  s->_pHead->_pNext = NULL;
}

void SListDestroy(SList *s){
  s->_pHead = NULL;
}

void PrintSList(SList *s){
  assert(s);
  PNode pCur = s->_pHead;
  while(pCur){
    printf("%d--->",pCur->_data);
    pCur = pCur->_pNext;
  }
  printf("NULL\n");
}

void Test(){
  SList s;
  SListInit(&s);
  SListPushBack(&s,2);
  SListPushBack(&s,4);
  SListPushFront(&s,1);
  SListPushFront(&s,0);
  //SListInsert(3, 3);
  PrintSList(&s);

  SListPopFront(&s);
  SListPopBack(&s);
  PrintSList(&s);

  printf("size=%d\n", SListSize(&s));
  SListClear(&s);
  PrintSList(&s);
}
