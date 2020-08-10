#include "Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void StackInit(Stack* s, int capacity)
{
  s->_array = (STDatatype*)malloc(sizeof(STDatatype) * capacity);
  if(NULL == s->_array)
  {
    assert(0);
    return;
  }
  s->_size = 0;
  s->_capacity = capacity;
}

void StackFull(Stack* s)
{
  assert(s);
  if(s->_size == s->_capacity)
  {
    int newCapacity = s->_capacity * 2;
    int* pTem = (STDatatype*)malloc(sizeof(STDatatype) * newCapacity);
    if(NULL == pTem)
    {
      assert(0);
      return;
    }
    int i;
    for(i = 0; i < s->_size; ++i)
    {
      pTem[i] = s->_array[i];
    }
    free(s->_array);
    s->_array = NULL;
    s->_array = pTem;
    s->_capacity = newCapacity;
  }
}

int StackEmpty(Stack* s)
{
  assert(s);
  return 0 == s->_size;
}

void StackPush(Stack* s, STDatatype data)
{
  assert(s);
  StackFull(s);
  s->_array[s->_size] = data;
  s->_size++;
}

void StackPop(Stack *s)
{
  assert(s);
  StackEmpty(s);
  s->_size--;
}

STDatatype StackTop(Stack* s)
{
  assert(s);
  if(StackEmpty(s))
  {
    return -1;
  }
  return s->_array[s->_size - 1];
}

int StackSize(Stack* s)
{
  assert(s);
  return s->_size;
}

int StackCapacity(Stack* s)
{
  assert(s);
  return s->_capacity;
}

void Destroy(Stack* s)
{
  assert(s);
  if(s->_array)
  {
    free(s->_array);
    s->_array = NULL;
    s->_size = 0;
    s->_capacity = 0;
  }
}

void Print(Stack* s)
{
  assert(s);
  int i;
  for(i = 0; i < s->_size; ++i)
  {
    printf("%d", s->_array[i]);
  }
  printf("\n");
}

void Test()
{
  Stack s;
  StackInit(&s, 5);

  StackPush(&s, 1);
  StackPush(&s, 2);
  StackPush(&s, 3);
  StackPush(&s, 4);
  StackPush(&s, 5);
  Print(&s);
  printf("size = %d\n", StackSize(&s));
  printf("capacity = %d\n", StackCapacity(&s));

  StackPush(&s, 6);
  printf("size = %d\n", StackSize(&s));
  printf("capacity = %d\n", StackCapacity(&s));
  printf("top = %d\n", StackTop(&s));

  StackPop(&s);
  Print(&s);

  Destroy(&s);
  printf("top = %d\n", StackTop(&s));

}
