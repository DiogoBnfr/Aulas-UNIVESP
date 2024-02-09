#include <stdio.h>

int main() {
  int x = 25;
  int *y = &x;  // *y is a pointer who receives the memory address of x
  *y = 30;      // *y go to the memory address stored in *y and insert 30
  printf("The actual value of x is: %i\n", x);
  return 0;
}