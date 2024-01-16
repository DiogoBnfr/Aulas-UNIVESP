#include <stdio.h>

int squared_cubed(int x, int* y) {
  *y = x * x * x;
  return x * x;
}

int main() {
  int x = 30;
  int cube;
  int square = squared_cubed(x, &cube);
  printf("x: %i\nx * x: %i\nx * x * x: %i\n", x, square, cube);
  return 0;
}