#include "Queue.h"
#include <stdio.h>
#include <malloc.h>

QueueNode* GetNewNode(QDatatype data)
{
  QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
  if(NULL == pNewNode)
  {
    return NULL;
  }
  pNewNode->_data = data;
  pNewNode->_next = NULL;
  return pNewNode;
}

void QueueInit(Queue* q)
{
  q->_front = NULL;
  q->_rear = NULL;
}

void QueuePush(Queue* q, QDatatype data)
{
  QueueNode* pNewNode = GetNewNode(data);
  if(NULL == q->_front)
  {
    q->_front = pNewNode;
    q->_rear = q->_front;
  }
  else
  {
    QueueNode* pCur = q->_front;
    while(NULL != pCur->_next)
    {
      pCur = pCur->_next;
    }
    pCur->_next = pNewNode;
    q->_rear = pNewNode;
  }
}

void QueuePop(Queue* q)
{
  if(NULL == q->_front)
  {
    return;
  }
  QueueNode* pCur = q->_front;
  while(pCur->_next != q->_rear)
  {
    pCur = pCur->_next;
  }
  free(q->_rear);
  q->_rear = pCur;
  q->_rear->_next = NULL;
}

QDatatype QueueFront(Queue* q)
{
  if(NULL == q->_front)
  {
    return -1;
  }
  return q->_front->_data;
}

QDatatype QueueBack(Queue* q)
{
  if(NULL == q->_front)
  {
    return -1;
  }
  return q->_rear->_data;
}

int QueueSize(Queue* q)
{
  int count;
  if(NULL == q->_front)
  {
    return 0;
  }
  QueueNode* pCur = q->_front;
  count = 1;
  while(NULL != pCur->_next)
  {
    count++;
    pCur = pCur->_next;
  }
  return count;
}

int QueueEmpty(Queue* q)
{
  return 0 == QueueSize(q);
}

void QueueDestroy(Queue* q)
{
  q->_front = NULL;
}

void Print(Queue* q)
{
  if(NULL == q->_front)
  {
    return;
  }
  QueueNode* pCur = q->_front;
  while(NULL != pCur->_next)
  {
    printf("%d--->", pCur->_data);
    pCur = pCur->_next;
  }
  printf("%d--->", pCur->_data);
  printf("NULL\n");
}

void Test()
{
  Queue q;
  QueueInit(&q);
  QueuePush(&q, 0);
  QueuePush(&q, 1);
  QueuePush(&q, 2);
  QueuePush(&q, 3);
  QueuePush(&q, 4);
  QueuePush(&q, 5);
  Print(&q);

  QueuePop(&q);
  QueuePop(&q);
  QueuePop(&q);
  Print(&q);

  printf("队头元素：%d\n", QueueFront(&q));
  printf("队尾元素：%d\n", QueueBack(&q));
  printf("元素个数：%d\n", QueueSize(&q));

  QueueDestroy(&q);
}
