#ifndef _QUEUE_H_
#define _QUEUE_H_ 

typedef int QDatatype;

typedef struct QueueNode
{
  struct QueueNode* _next;
  QDatatype _data;
}QueueNode;

typedef struct Queue
{
  QueueNode* _front;
  QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
QueueNode* GetNewNode(QDatatype data);
void QueuePush(Queue* q, QDatatype data);
void QueuePop(Queue* q);
QDatatype QueueFront(Queue* q);
QDatatype QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);

void Test();

#endif
