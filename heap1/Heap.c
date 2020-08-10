#include "Heap.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>


void Swap(HPDataType* pLeft, HPDataType* pRight)
{
	HPDataType temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}


void AdjustDown(HPDataType* array, int size, int parent, PCOM Compare)
{
	// Ĭ����child���parent�����ӣ���Ϊ����ȫ������ĳ���ڵ����ֻ��һ�����ӣ��ú���һ������˫�׵�����
	int child = parent * 2 + 1;

	while (child < size)
	{
		// ��˫�׺����н�С�ĺ���
		if (child + 1 < size && Compare(array[child + 1], array[child]))
		{
			child += 1;
		}

		if (Compare(array[child],array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void AdjustUP(HPDataType* array, int size, int child, PCOM Compare)
{
	int parent = (child - 1) / 2;

	while (child)
	{
		if (Compare(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}

void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity * 2;

		// �����¿ռ�
		HPDataType* pTemp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}

		// ����Ԫ��
		for (int i = 0; i < hp->_size; ++i)
			pTemp[i] = hp->_array[i];

		// �ͷžɿռ�
		free(hp->_array);

		hp->_array = pTemp;
		hp->_capacity = newCapacity;
	}
}

int Less(HPDataType left, HPDataType right)
{
	return left < right;
}

int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}

void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare)
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*size);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}

	hp->_capacity = size;
	for (int i = 0; i < size; ++i)
		hp->_array[i] = array[i];

	hp->_size = size;
	hp->Compare = compare;

	// ������ȫ������������������ѵ�����

	// ����ȫ�������е�����һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root)
		AdjustDown(hp->_array, size, root, hp->Compare);
}

void InitEmptyHeap(Heap* hp, int capacity, PCOM compare)
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType)*capacity);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}

	hp->_capacity = capacity;
	hp->_size = 0;
	hp->Compare = compare;
}

void InsertHeap(Heap* hp, HPDataType data)
{
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustUP(hp->_array, hp->_size, hp->_size - 1, hp->Compare);
}

void EraseHeap(Heap* hp)
{
	if (HeapEmpty(hp))
		return;

	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->_array, hp->_size, 0, hp->Compare);
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

void TestHeap1()
{
	Heap hp;
	int array[] = {2,3,8,0,9,1,7,4,6,5};
	InitHeap(&hp, array, sizeof(array) / sizeof(array[0]), Less);
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));

	EraseHeap(&hp);
	printf("%d\n", HeapTop(&hp));

	InsertHeap(&hp, 0);
	printf("%d\n", HeapTop(&hp));
	DestroyHeap(&hp);
}

void TestHeap2()
{
	Heap hp;
	InitEmptyHeap(&hp, 10, Greater);
	
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	for (int i = 0; i < 10; ++i)
		InsertHeap(&hp, array[i]);
	
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
	DestroyHeap(&hp);
}

void HeapAdjust(int* array, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		// �����Һ����нϴ�ĺ���
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int* array, int size)
{
	// 1. ����---��ѣ�С�ѣ�  
	// �ҵ�����һ����Ҷ�ӽڵ�
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root)
		HeapAdjust(array, size, root);

	// 2. ����: ɾ����ʽ
	int end = size - 1;
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}

void TestHeap()
{
	//TestHeap1();
	//TestHeap2();
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	HeapSort(array, sizeof(array)/sizeof(array[0]));
}