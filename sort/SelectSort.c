#include <stdio.h>

//选择排序
void Swap(int* pLeft, int* pRight)
{
  int temp = *pLeft;
  *pLeft = *pRight;
  *pRight = temp;
}

void SelectSort(int* array, int size)
{
  int i;
  for(i = 0; i < size - 1; ++i)
  {
    int maxPos = 0;
    int j;
    for(j = 1; j < size - i; ++j)
    {
      if(array[j] > array[maxPos])
      {
        maxPos = j;
      }
    }
    if(maxPos != size - i - 1)
    {
      Swap(&array[maxPos], &array[size - i - 1]);
    }
  }
}

int main()
{
  int array[10] = {9, 0, 3, 6, 2, 7, 5, 1, 8, 4};
  SelectSort(array, 10);
  int i;
  for(i = 0; i < 10; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
