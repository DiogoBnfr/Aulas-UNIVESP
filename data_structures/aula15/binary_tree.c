#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int KEY_TYPE;

typedef struct aux {
	KEY_TYPE key;
	struct aux *left, *right;
} NODE;

typedef struct {
	NODE* data;
} BINARY_TREE;
