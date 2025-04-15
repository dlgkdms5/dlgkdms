#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rows;
	int cols;
	int** data;
}Matrix;

Matrix matrix_make(int rows, int cols) {
	Matrix mat;
	mat.rows = rows;
	mat.cols = cols;

	mat.data = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++)
		mat.data[i] = (int*)malloc(cols * sizeof(int));
	return mat;
}

void freeMatrix(Matrix* mat) {
	for (int i = 0; i < mat->rows; i++) {
		free(mat->data[i]);
	}
	free(mat->data);
	mat->data = NULL;
}

void multiArray(Matrix* m1, Matrix* m2) {
	for (int i = 0; i < m1->rows; i++) {
		for (int j = 0; j < m2->cols; j++) {
			int h = 0;
			for (int z = 0; z < m1->cols; z++)
				h += m1->data[i][z] * m2->data[z][j];
			printf("%d ", h);
		}
		printf("\n");
	}
}

int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	Matrix m1 = matrix_make(R, C);
	scanf("%d %d", &R, &C);
	Matrix m2 = matrix_make(R, C);
	if (m1.cols == m2.rows) printf("ok\n");
	else {
		printf("no\n");
		return 0;
	}

	printf("1번째 행렬 입력:\n");
	for (int i = 0; i < m1.rows; i++) {
		for (int j = 0; j < m1.cols; j++)
			scanf("%d", &m1.data[i][j]);
	}
	printf("2번째 행렬 입력:\n");
	for (int i = 0; i < m2.rows; i++) {
		for (int j = 0; j < m2.cols; j++)
			scanf("%d", &m2.data[i][j]);
	}
	printf("\n");

	multiArray(&m1, &m2);

	freeMatrix(&m1);
	freeMatrix(&m2);
}
