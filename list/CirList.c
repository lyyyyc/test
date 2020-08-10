#include "CirList.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int Menu()
{
  printf("====================\n");
  printf("1.增加结点\n");
  printf("2.删除结点\n");
  printf("3.清空链表\n");
  printf("4.获取结点个数\n");
  //printf("5.排序\n");
  printf("5.打印链表\n");
  printf("6.销毁链表\n");
  printf("0.退出\n");
  printf("====================\n");
  printf("请输入：");
  int choice = 0;
  scanf("%d", &choice);
  return choice;
}

void CListInit(CList *c)
{
  assert(c);
  c->_pHead = NULL;
}

pNode BuyNewNode(CListData data)
{
  pNode pNewNode = (pNode)malloc(sizeof(Node));
  if(NULL == pNewNode)
  {
    assert(0);
    return NULL;
  }
  pNewNode->_data = data;
  pNewNode->_pNext = NULL;
  pNewNode->_pPrev = NULL;
  return pNewNode;
}

void CListPushBack(CList *c, CListData data)
{
  assert(c);
  pNode pNewNode = BuyNewNode(data);
  if(NULL == c->_pHead)
  {
    c->_pHead = pNewNode;
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
  assert(c);
  if(NULL == c->_pHead)
  {
    return;
  }
  else if(NULL == c->_pHead->_pNext)
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
  c->_pHead = c->_pHead->_pNext;
  CListPopBack(c);
}

void CListInsert(CList *c, int pos, CListData data)
{
  assert(c);
  int count = Size(c) - 1;
  if(pos < 0 | pos > count)
  {
    return;
  }
  pNode pNewNode = BuyNewNode(data);
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
    pNewNode->_pNext = pCur->_pNext;
    pCur->_pNext->_pPrev = pNewNode;
    pNewNode->_pPrev = pCur;
    pCur->_pNext = pNewNode;
  } 
}

void CListErase(CList *c, int pos)
{
  assert(c);
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
  assert(c);
  if(NULL == c->_pHead)
  {
    return;
  }
  c->_pHead->_pNext = NULL;
  c->_pHead->_pPrev = NULL;
}

void CListSize(CList *c)
{
  assert(c);
  if(NULL == c->_pHead)
  {
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
  assert(c);
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
  assert(c);
  pNode pCur = c->_pHead;
  int count = 0;
  while(pCur->_data != data)
  {
    pCur = pCur->_pNext;
    count++;
  }
  return count;
}

/*void CListSort(CList *c)
 * {
  assert(s);
  
}*/

void Print(CList *c)
{
  assert(c);
  pNode pCur = c->_pHead;
  if(NULL == c->_pHead)
  {
    return;
  }
  else if(NULL == c->_pHead->_pNext)
  {
    printf("%s<--->%s", pCur->_data, pCur->_data);
  }
  else
  {
    printf("%s<--->", pCur->_data);
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
  assert(c);
  c->_pHead = NULL;
}

int AddNode()
{
  printf("新增结点\n");
  printf("====================\n");
  printf("1.头部新增\n");
  printf("2.尾部新增\n");
  printf("3.选择新增\n");
  printf("0.返回\n");
  printf("====================\n");
  printf("请输入：");
  int choice1 = 0;
  scanf("%d", &choice1);
  return choice1;
}

int DelNode()
{
  printf("删除结点\n");
  printf("====================\n");
  printf("1.头部删除\n");
  printf("2.尾部删除\n");
  printf("3.选择删除\n");
  printf("0.返回\n");
  printf("====================\n");
  printf("请输入：");
  int choice2 = 0;
  scanf("%d", &choice2);
  return choice2;
}

int main()
{
  CList c;
  CListInit(&c);

  while(1)
  {
    int choice = Menu();
    if(choice < 0 || choice > 6)
    {
      printf("输入有误，请重新输入：\n");
      continue;
    }
    else if(0 == choice){
      printf("再见\n");
      break;
    }
    else if(1 == choice)
    {
      while(1){
        int choice1 = AddNode();
        if(choice1 < 0 || choice1 > 3)
        {
          printf("输入有误，请重新输入：\n");
          continue;
        }
        if(0 == choice1)
        {
          break; 
        }
        else if(1 == choice1)
        {
          CListData data = 0;
          printf("请输入您要插入的值：");
          scanf("%s", data);
          CListPushFront(&c, data);
          printf("插入成功\n");
        }
        else if(2 == choice1)
        {
          CListData data = 0;
          printf("请输入您要插入的值：");
          scanf("%s", data);
          CListPushBack(&c, data);
          printf("插入成功\n");
        }
        else
        {
         int pos = 0; 
         CListData data = 0;
         printf("请输入您要插入的位置和值：");
         scanf("%d %s", pos, data);
         printf("插入成功\n");
        }
        break;
      }
      choice = 0;
      continue;
    }
    else if(2 == choice)
    {
      while(1)
      {
        int choice2 = DelNode();
        if(choice2 < 0 || choice2 > 3)
        {
          printf("输入有误，请重新输入：\n");
          continue;     
        }
        if(0 == choice2)
        {
          break;
        }
        else if(1 == choice2)
        {
          CListPopFront(&c);
          printf("删除成功\n");
        }
        else if(2 == choice2)
        {
          CListPopBack(&c);
          printf("删除成功\n");
        }
        else
        {
          int pos = 0;
          printf("请输入要删除的结点位置：");
          scanf("%d", pos);
          printf("删除成功\n");
        }
        break;
      }
      choice = 0;
      continue;
    }
    else if(3 == choice)
    {
      CListClear(&c);
      printf("链表清空成功\n");
      continue;
    }
    else if(4 == choice)
    {
      CListSize(&c);
      continue;
    }
    else if(5 == choice)
    {
      Print(&c);
      continue;
    }
    else
    {
      Destroy(&c);
      printf("链表已销毁\n");
      break;
    }
  }
  return 0;
}
