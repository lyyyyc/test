#pragma once 
typedef int DataType;
typedef struct SeqList{
  DataType* _array;
  int _size;
  int _capacity;
}SeqList, *PSeq;

void SeqListInit(PSeq ps, int capacity);
void SeqListPushBack(PSeq ps, DataType data);
void SeqListPopBack(PSeq ps);
void SeqListPushFront(PSeq ps, DataType data);
void SeqListPopFront(PSeq ps);
void SeqListInsert(PSeq ps, int pos, DataType data);
void SeqListErase(PSeq ps, int pos);
int SeqListFind(PSeq ps, DataType data);
int isEmpty(PSeq ps);
int Size(PSeq ps);
int Capacity(PSeq ps);
void Clear(PSeq ps);
void SeqListRemove(PSeq ps, DataType data);
void Destroy(PSeq ps);
void CheckCapacity(PSeq ps);
void BubbleSort(PSeq ps);
void SeqListRemoveAll(PSeq ps, DataType data);
void Test();
