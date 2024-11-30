#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol) {
	Matrix* m = malloc(sizeof(Matrix));

	m->ncol = ncol;
	m->nlin = nlin;

	m->mat = malloc(sizeof(int *) * nlin);

	for (int i = 0; i < nlin; i++) {
		m->mat[i] = malloc(sizeof(int) * ncol);
	}

	return m;
}

void readMatrix(Matrix *m) {
	for (int i = 0; i < m->nlin; i++) {
		for (int j = 0; j < m->ncol; j++) {
			scanf("%d", &m->mat[i][j]);
		}
	}
}

void printMatrix(Matrix *m) {
	for (int i = 0; i < m->nlin; i++) {
		for (int j = 0; j < m->ncol; j++) {
			printf("%d", m->mat[i][j]);

			if (j < m->ncol-1) {
        		printf(" ");
			} else {
        		printf("\n");
			}
		}
	}
};
void destroyMatrix(Matrix **m) {
	Matrix* ptr_m = *m;

  	for (int i = 0; i  < ptr_m->nlin; i++) {
    	free(ptr_m->mat[i]);
	}

  	free(ptr_m);
  	*m = NULL;
};

int main() {
	int lin, col;
	Matrix* mat;

	scanf("%i %i", &lin, &col);
	mat = createMatrix(lin, col);

	readMatrix(mat);
	printMatrix(mat);
	destroyMatrix(&mat);

	if (mat == NULL) {
		printf("OK\n");
	}

	return 0;
}