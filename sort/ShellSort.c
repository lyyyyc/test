#include <stdio.h>

//希尔排序
void ShellSort(int* array, int size)
{
  int gap = 3;
  while(gap > 0)
  {
    int i;
    for(i = gap; i < size; ++i)
    {
      int key = array[i];
      int end = i - gap;
      while(end >= 0 && key < array[end])
      {
        array[end + gap] = array[end];
        end -= gap;
      }
      array[end + gap] = key;
    }
    gap -= 1;
  }
}


int main()
{
  int array[10] = {9, 0, 3, 6, 2, 7, 5, 1, 8, 4};
  ShellSort(array, 10);
  int i;
  for(i = 0; i < 10; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
