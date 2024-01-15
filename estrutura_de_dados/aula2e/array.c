#include <stdio.h>
#include <stdlib.h>

void print_array(int *w) {
  printf("w0: %i, w1: %i, w2 %i\n", w[0], w[1], w[2]);
  // print the x array values

  printf("&w: %p, w: %p, *w: %i\n", &w, w, *w);
  // &w: w memory address, w: x memory address, *w: value in x memory address

  w[0] += 10;
  w[1] += 10;
  w[2] += 10;

  if (*w < 100) print_array(w);
}

int main() {
  int x[3];
  x[0] = 1;
  x[1] = 2;
  x[2] = 7;

  printf("x0: %d, x1: %d, x2: %d\n", x[0], x[1], x[2]);
  // print the array values

  printf("&x: %p, x: %p, *x: %i\n", &x, x, *x);
  // &x: memory address, x: memory address, *x: value

  print_array(x);
}