//question 01
#include <stdio.h>
#include <stdlib.h>

float *allocate_vector(int size) {
    float *result = (float *) malloc(sizeof(float) * size);

    if (result != NULL) {
        return result;
    } else {
        free(result);
        return NULL;
    }
}

float **allocate_matrix(int rows, int columns) {
    float **result = (float **) malloc(sizeof(float *) * rows);

    if (result != NULL) {
        for (int i = 0; i < rows; i++) {
            result[i] = (float *) malloc(sizeof(float) * columns);
            if (result[i] == NULL) {
                for (int j = i - 1; j > 0; j--) {
                    free(result[i]);
                }
                free(result);
            }
        }
    }

    return result;
}

float *random_vector(float *vector, int size, int range) {
    for (int i = 0; i < size; ++i) {
        vector[i] = rand() % range;
    }
    return vector;
}

float **random_matrix(float **matrix, int rows, int columns, int range) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = rand() % range;
        }
    }
    return matrix;
}

void view_vector(float *vector, int size) {
    for (int i = 0; i < size; ++i) {
        printf(" [%f] ", vector[i]);
    }
    printf("\n");
}

void view_matrix(float **matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf(" [%f] ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void CmpVectorMatrix(int n, int m, int p, float *vet, float **mat) {
    for (int i = 0; i < n; ++i) {
        float vector_element = vet[i];
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                float matrix_element = mat[j][k];
                if (vector_element == matrix_element) {
                    printf("vector[%d] == matrix[%d][%d] == %f\n", i, j, k, vector_element);
                }
            }
        }
    }
}

int main() {
    int n = 10, m = 2, p = 2;

    float *vector;
    float **matrix;

    vector = allocate_vector(n);
    matrix = allocate_matrix(m, p);

    vector = random_vector(vector, n, n);
    matrix = random_matrix(matrix, m, p, 10);

    view_vector(vector, n);
    view_matrix(matrix, m, p);

    CmpVectorMatrix(n, m, p, vector, matrix);
    return 0;
}