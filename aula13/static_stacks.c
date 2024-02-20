#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int KEY_TYPE;

typedef struct {
	KEY_TYPE key;
} REGISTER;

typedef struct {
	REGISTER data[MAX];
	int head1;
	int head2;
} DOUBLE_STACK; 

void init_ds(DOUBLE_STACK* ds) {
	ds->head1 = -1;
	ds->head2 = MAX;
}

int size_ds(DOUBLE_STACK ds) {
	return (ds.head1 + 1) + (MAX - ds.head2);
}

void print_ds(DOUBLE_STACK* ds, int direction) {
	printf("[ ");
	if (direction == 0)	{
		for (int i = ds->head1; i >= 0; i--) {
			printf("%i ", ds->data[i].key);
		}
	} else {
			for (int i = ds->head2; i < MAX; i++) {
				printf("%i ", ds->data[i].key);
			}
	}
	printf("]");
}

bool push_ds(DOUBLE_STACK* ds, int direction, REGISTER reg) {
	if (ds->head1 + ds->head2 == MAX) return false;
	if (direction == 0) {
		ds->head1++;
		ds->data[ds->head1] = reg;
	} else {
		ds->head2--;
		ds->data[ds->head2] = reg;
	}
	return true;
}

bool pop_ds(DOUBLE_STACK* ds, int direction, REGISTER* reg) {
	if (direction == 0) {
		if (ds->head1 == -1) return false;
		*reg = ds->data[ds->head1];
		ds->head1--;
	} else {
		if (ds->head2 == MAX) return false;
		*reg = ds->data[ds->head2];
		ds->head2++;
	}
	return true;
}

void reboot_ds(DOUBLE_STACK* ds) {
	init_ds(ds);
}
