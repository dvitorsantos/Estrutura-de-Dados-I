//question 05
#include <stdio.h>
#include <stdlib.h>

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

int *TrianguloSuperiorDeMat (int *vma, int n, int m) {
    if (n != m) {
        printf("error: matrix must be a square matrix.\n");
        return NULL;
    }

    int *result = (int *) malloc(sizeof(int) * n*m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j >= i) {
                result[i*m+j] = vma[i*m+j];
            }
        }
    }

    return result;
}


int main() {
    int n = 3, m = 3;
    int *matrix = random_vector(allocate_vector(n*m), n*m, 5);

    view_matrix(matrix, n, m);

    view_matrix(TrianguloSuperiorDeMat(matrix, n, m), n, m);

    return 0;
}