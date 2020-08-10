#pragma once 

typedef int STDatatype;
typedef struct Stack
{
  STDatatype* _array;
  int _capacity;
  int _size;
}Stack;

void StackInit(Stack* s, int capacity);
void StackFull(Stack* s);
void StackPush(Stack* s, STDatatype data);
void StackPop(Stack *s);
STDatatype StackTop(Stack* s);
int StackEmpty(Stack* s);
int StackSize(Stack* s);
int StackCapacity(Stack* s);
void Destroy(Stack* s);

void Test();
