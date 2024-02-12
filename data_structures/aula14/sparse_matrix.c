#include <malloc.h>
#include <stdbool.h>

typedef  struct aux {
	float value;
	int column;
	struct aux* next;
} NODE;

typedef struct {
	NODE** data;
	int rows;
	int columns;
} SPARSE_MATRIX;

void init_sm(SPARSE_MATRIX* sm, int rows, int col) {
	sm->rows = rows;
	sm->columns = col;
	sm->data = (NODE**)malloc(rows * sizeof(NODE*));
	for (int i = 0; i < rows; i++) sm->data[i] = NULL;
}

bool insert_sm(SPARSE_MATRIX* sm, int row, int col, float val) {
	if (row < 0 || row >= sm->rows || col < 0 || col >= sm->columns)
		return false;
	NODE* prev = NULL;
	NODE* current = sm->data[row];
	while (current != NULL && current->column < col) {
		prev = current;
		current = current->next;
	}
	if (current != NULL && current->column == col) {
		if (val == 0) {
			if (prev == NULL) sm->data[row] =  current->next;
			else prev->next = current->next;
			free(current);
		}
		else current->value = val;
	}
	else {
		NODE* new = (NODE*)malloc(sizeof(NODE));
		new->column = col;
		new->value = val;
		new->next = current;
		if (prev == NULL) sm->data[row] = new;
		else prev->next = new;
	}
	return true;
}

float value_sm(SPARSE_MATRIX* sm, int row, int col) {
	if (row < 0 || row >= sm->rows || col < 0 || col >= sm->columns)
		return 0;
	NODE* current = sm->data[row];
	while (current != NULL && current->column < col) current = current->next;
	if (current != NULL && current->column == col) return current->value;
	return 0;
}
