#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// standard way to declare matrix
	int m[2][3];

	m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[1][0] = 4;
	m[1][1] = 5;
	m[1][2] = 6;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("m(%d, %d): %d\n", i, j, m[i][j]);
		}
	}
	printf("\n");

	// alternative way to declare matrix
	int** M = (int**)malloc(sizeof(int*)*2);

	for (int i = 0; i < 2; i++) {
		M[i] = (int*) malloc(sizeof(int)*3);
	}

	M[0][0] = 1;
	M[0][1] = 2;
	M[0][2] = 3;
	M[1][0] = 4;
	M[1][1] = 5;
	M[1][2] = 6;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("M(%d, %d): %d\n", i, j, M[i][j]);
		}
	}
}
