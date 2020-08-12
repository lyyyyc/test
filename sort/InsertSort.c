#include <stdio.h>

//插入排序
void InsertSort(int* array, int size)
{
  int i;
  for(i = 1; i < size; ++i)
  {
    int key = array[i];
    int end = i - 1;
    while(end >= 0 && key < array[end])
    {
      array[end + 1] = array[end];
      end -= 1;
    }
    array[end + 1] = key;
  }
}

int main()
{
  int array[10] = {9, 0, 3, 6, 2, 7, 5, 1, 8, 4};
  InsertSort(array, 10);
  int i;
  for(i = 0; i < 10; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
