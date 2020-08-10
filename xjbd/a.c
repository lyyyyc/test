#include <stdio.h>

int main(){
  int i;
  int c[4] = {1, 2, 3, 4};
  int d[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int *a[4];
  int (*b)[4];
  b = d;
  for(i = 0; i < 4; ++i){
    a[i] = &c[i];
  }
  printf("%d\n", **b);
  printf("%d\n", *b[0]);
  printf("%d\n", **(b+1));
  printf("%d\n", *(b+1)[0]);
  printf("%d\n", **(b+2));
  printf("%d\n", *(b+2)[0]);
  return 0;
}
