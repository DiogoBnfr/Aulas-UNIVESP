#include <malloc.h>
#include <stdio.h>

int main() {
  int *y = (int *)malloc(sizeof(int));
  *y = 20;
  int z = sizeof(int);
  printf("*y=%i z=%i\n", *y, z);
  // y print the memory address, *y print the data in the memory address
  return 0;
}