#include <malloc.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef int bool;

typedef struct {
	int order;
	int* data;
} LTM;

void init_ltm(int n, LTM* matrix) {
	matrix->order = n;
	int size = (n + n * n) / 2;
	matrix->data = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) matrix->data[i] = 0;
}

int return_index(int row, int col) {
	return (row * row - row) / 2 + col - 1;
}

int assign_matrix(int row, int col, int val, LTM* matrix) {
	if (row < 1 || row > matrix->order || 
			col < 1 || col > matrix->order || 
			row < col) return false;
	int i = return_index(row, col);
	matrix->data[i] = val;
	return true;
}

int return_value(int row, int col, LTM* matrix) {
	if (row < 1 || row > matrix->order || 
			col < 1 || col > matrix->order) return 0;
	if (row < col) return 0;
	return matrix->data[return_index(row, col)];
}
