#ifndef _DEFCIRLIST_H_
#define _DEFCIRLIST_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1024


typedef struct CListNode
{
  char _data[MAXLEN];
  struct CListNode* _pPrev;
  struct CListNode* _pNext;
}pNode;

typedef struct CList
{
  pNode* _pHead;
  int _len;
}CList;

#endif
