#include <stdio.h>

//冒泡排序
void Swap(int* pLeft, int* pRight)
{
  int temp = *pLeft;
  *pLeft = *pRight;
  *pRight = temp;
}

void BubbleSort(int* array, int size)
{
  int i, j;
  for(i = 0; i < size - 1; ++i)
  {
    for(j = 0; j < size - 1; ++j)
    {
      if(array[j] > array[j+1])
      {
        Swap(&array[j], &array[j+1]);
      }
    }
  }
}

int main()
{
  int array[10] = {9, 0, 3, 6, 2, 7, 5, 1, 8, 4};
  BubbleSort(array, 10);
  int i;
  for(i = 0; i < 10; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
