#include <stdio_ext.h>

void Swap(int* pLeft, int* pRight)
{
  int temp = *pLeft;
  *pLeft = *pRight;
  *pRight = temp;
}

int GetMiddleIndex(int* array, int left, int right)
{
  int mid = left + ((right - left) >> 1);
  if(array[left] < array[right - 1])
  {
    if(array[mid] < array[left])
    {
      return left;
    }
    else if(array[mid] > array[right - 1])
    {
      return right - 1;
    }
    else 
    {
      return mid;
    }
  }
  else
  {
    if(array[mid] > array[left])
    {
      return left;
    }
    else if(array[mid] < array[right - 1])
    {
      return right - 1;
    }
    else 
    {
      return mid;
    }
  }
}

int Partion_Hoare(int* array, int left, int right)
{
  int begin = left;
  int end = right - 1;
  int mid = GetMiddleIndex(array, left, right);
  Swap(&array[mid], &array[right - 1]);
  int key = array[right - 1];
  while(begin < end)
  {
    //从左往右找比基准值大的元素，找到后停止
    while(begin < end && array[begin] <= key)
    {
      begin++;
    }
    //从右往左找比基准值小的元素，找到后停止
    while(begin < end && array[end] >= key)
    {
      end--;
    }
    if(begin != end)
    {
      Swap(&array[begin], &array[end]);
    }
  }
  if(begin != right - 1)
  {
    Swap(&array[begin], &array[right - 1]);
  }
  return begin;
}

//挖坑法
int Partion_WK(int* array, int left, int right)
{
  //i=L;j=R;将基准数挖出形成第一个坑array[i]
  //j--由后向前找比它小的数，找到后挖出此数填到前一个坑array[i]中
  //i++由前向后找比它大的数，找到后挖出此数填到前一个坑array[j]中
  //重复前两步操作，直到i==j，将基准数填到array[i]中
  int begin = left;
  int end = right - 1;
  int mid = GetMiddleIndex(array, left, right);
  Swap(&array[mid], &array[right - 1]);
  int key = array[right - 1];
  while(begin < end)
  {
    while(begin < end && array[begin] <= key)
    {
      begin++;
    }
    if(begin <end)
    {
      array[end] = array[begin];
      end--;
    }
    while(begin < end && array[end] >= key)
    {
      end--;
    }
    if(begin < end)
    {
      array[begin] = array[end];
      begin++;
    }
  }
  array[begin] = key;
  return begin;
}

void QuickSort(int* array, int left, int right)
{
  //按照基准值将区间分割成左右两部分
  //左侧小于基准值，右侧大于基准值
  int div = Partion_WK(array, left, right);
  QuickSort(array, left, div);
  QuickSort(array, div + 1, right);
}

int main()
{
  int array[10] = {9, 0, 3, 6, 2, 7, 5, 1, 8, 4};
  QuickSort(array, array[0], array[9]);
  int i;
  for(i = 0; i < 10; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  return 0;
}
