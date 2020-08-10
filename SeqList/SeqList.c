#include "SeqList.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void SeqListInit(PSeq ps, int capacity){
  ps->_array = (DataType*)malloc(sizeof(DataType) * capacity);
  if(ps->_array == NULL){
    assert(0);
    return;
  }
  ps->_capacity = capacity;
  ps->_size = 0;
}

void CheckCapacity(PSeq ps){
  assert(ps);
  if(ps->_size == ps->_capacity){
    int newCapacity = ps->_capacity * 2;
    int *pTmp = (DataType*)malloc(sizeof(DataType) * newCapacity);
    if(pTmp == NULL){
      assert(0);
      return;
    }
    for(int i = 0; i < ps->_size; ++i){
      pTmp[i] = ps->_array[i];
    }
    free(ps->_array);
    ps->_array = pTmp;
    ps->_capacity = newCapacity;
  }
}

int isEmpty(PSeq ps){
  assert(ps);
  return ps->_size == 0; 
}

void SeqListPushBack(PSeq ps, DataType data){
  assert(ps);
  CheckCapacity(ps);
  ps->_array[ps->_size] = data;
  ps->_size++;
}

void SeqListPopBack(PSeq ps){
  assert(ps);
  if(isEmpty(ps)){
    return;
  }
  ps->_size--;
}

void SeqListPushFront(PSeq ps, DataType data){
  assert(ps);
  CheckCapacity(ps);
  for(int i = ps->_size - 1; i >= 0; i--){
    ps->_array[i+1] = ps->_array[i];
  }
  ps->_array[0] = data;
  ps->_size++;
}

void SeqListPopFront(PSeq ps){
  assert(ps);
  if(isEmpty(ps)){
    return;
  }
  for(int i = 1; i < ps->_size; ++i){
    ps->_array[i-1] = ps->_array[i];
  }
  ps->_size--;
}

void SeqListInsert(PSeq ps, int pos, DataType data){
  assert(ps);
  if(pos < 0 | pos > ps->_size){
    return;
  }
  CheckCapacity(ps);
  for(int i = ps->_size-1; i >= pos; i--){
    ps->_array[i+1] = ps->_array[i];
  }
  ps->_array[pos] = data;
  ps->_size++;
}

void SeqListErase(PSeq ps, int pos){
  assert(ps);
  if(pos < 0 | pos > ps->_size){
    return;
  }
  if(isEmpty(ps)){
    return;
  }
  for(int i = pos + 1; i < ps->_size; ++i){
    ps->_array[i-1] = ps->_array[i];
  }
  ps->_size--;
}

int SeqListFind(PSeq ps, DataType data){
  assert(ps);
  for(int i = 0; i < ps->_size; ++i){
    if(ps->_array[i] == data){
      return i;
    }
  }
  return -1;
}

int Size(PSeq ps){
  assert(ps);
  return ps->_size;
}

int Capacity(PSeq ps){
  assert(ps);
  return ps->_capacity;
}

void Clear(PSeq ps){
  assert(ps);
  ps->_size = 0;
}

void SeqListRemove(PSeq ps, DataType data){
  SeqListErase(ps, SeqListFind(ps, data));
}

void SeqListRemoveAll(PSeq ps, DataType data){
  assert(ps);
  int count = 0;
  for(int i = 0; i < ps->_size; ++i){
    if(data == ps->_array[i]){
      count++;
    }
    else{
      ps->_array[i - count] = ps->_array[i];
    }
  }
  ps->_size -= count;
}

void Swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(PSeq ps){
  assert(ps);
  for(int i = 0; i < ps->_size - 1; ++i){
    int ischange = 0;
    for(int j = 0; j < ps->_size - 1; ++j){
      if(ps->_array[j] > ps->_array[j+1]){
        ischange = 1;
        Swap(&ps->_array[j], &ps->_array[j+1]);
      }
    }
  }
}

void Destroy(PSeq ps){
  if(ps->_array){
    free(ps->_array);
    ps->_array = NULL;
    ps->_capacity = 0;
    ps->_size = 0;
  }
}

void Print(PSeq ps){
  for(int i = 0; i < ps->_size; ++i){
    printf("%d, ", ps->_array[i]);
  }
  printf("\n");
}

void Test(){
  SeqList s;
  SeqListInit(&s, 10);
  SeqListPushBack(&s, 0);
  SeqListPushBack(&s, 1);
  SeqListPushBack(&s, 2);
  SeqListPushBack(&s, 3);
  SeqListPushBack(&s, 4);
  SeqListPushBack(&s, 5);
  SeqListPushBack(&s, 6);
  SeqListPushBack(&s, 7);
  SeqListPushBack(&s, 8);
  SeqListPushBack(&s, 9);
  Print(&s);
  printf("size:%d\n",Size(&s));
  printf("capacity:%d\n", Capacity(&s));
  SeqListPushBack(&s, 0);
  Print(&s);
  printf("capacity:%d\n", Capacity(&s));

  SeqListPopBack(&s);
  SeqListPopBack(&s);
  SeqListPopBack(&s);
  SeqListPopBack(&s);
  Print(&s);

  SeqListPushFront(&s, 9);
  SeqListPushFront(&s, 7);
  SeqListPushFront(&s, 8);
  Print(&s);

  SeqListPopFront(&s);
  SeqListPopFront(&s);
  Print(&s);

  SeqListInsert(&s, 6, 9);
  Print(&s);

  SeqListErase(&s, 1);
  Print(&s);

  SeqListRemove(&s, 3);
  Print(&s);

  SeqListRemoveAll(&s, 9);
  Print(&s);

  SeqListPushFront(&s, 3);
  Print(&s);

  BubbleSort(&s);
  Print(&s);

  Destroy(&s);
}
