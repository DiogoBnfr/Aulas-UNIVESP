#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3];
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    int *y = (int *)malloc(sizeof(int) * 3);
    y[0] = 4; // y[0] acess memory address y and move 0 addresses to insert 1
    y[1] = 5;
    y[2] = 6;

    int *w = y + 2; // w will now acess y[2]
    printf("x0: %d, x1: %d, x2: %d\n", x[0], x[1], x[2]);
    printf("y0: %d, y1: %d, y2: %d\n", y[0], y[1], y[2]);
    printf("&y: %p, y: %p, *y: %i, *w: %i\n", &y, y, *y, *w);

    *y = *x; // y[0] = 1
    printf("&y: %p, y: %p, *y: %i, *w: %i\n", &y, y, *y, *w);
    free(y);

    y = (int *)x; // y now points to x memory address
    printf("x0: %d, x1: %d, x2: %d\n", x[0], x[1], x[2]);
    printf("y0: %d, y1: %d, y2: %d\n", y[0], y[1], y[2]);
}