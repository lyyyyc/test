#pragma once

typedef int HPDataType;


typedef int (*PCOM)(HPDataType, HPDataType);
int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);

typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
	PCOM Compare;
}Heap;



void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare);
void InitEmptyHeap(Heap* hp, int capacity, PCOM compare);
void InsertHeap(Heap* hp, HPDataType data);
void EraseHeap(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);
void DestroyHeap(Heap* hp);


void TestHeap();

void HeapSort(int* array, int size);