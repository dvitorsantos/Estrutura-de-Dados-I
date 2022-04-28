//question 04
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int *allocate_vector(int size) {
    int *result = (int *) malloc(sizeof(int) * size);

    if (result != NULL) {
        return result;
    } else {
        free(result);
        return NULL;
    }
}

int *random_vector(int *vector, int size, int range) {
    for (int i = 0; i < size; ++i) {
        vector[i] = rand() % range;
    }
    return vector;
}

void view_matrix(int *matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf(" [%d] ", matrix[i*columns+j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ESimetrica ( int * vma, int n, int m) {
    if (n != m) {
        printf("error: matrix must be a square matrix.\n");
        return NULL;
    }

    int *vma_transposed = (int *) malloc(sizeof(int) * n*m);

    if (vma_transposed == NULL) {
        printf("error: malloc error.\n");
        return NULL;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vma_transposed[j*n+i] = vma[i*m+j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vma_transposed[i*m+j] != vma[i*m+j]) {
                return FALSE;
            }
        }
    }

    return TRUE;
}

int main() {
    int n = 2, m = 3;
    int *matrix = random_vector(allocate_vector(n*m), n*m, 5);

    view_matrix(matrix, n, m);

    if(ESimetrica(matrix, n, m) == TRUE){
        printf("simetric\n");
    }  else {
        printf("not simetric.\n");
    }

    return 0;
}