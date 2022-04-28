//question 01
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

void view_vector(int *vector, int size) {
    for (int i = 0; i < size; ++i) {
        printf(" [%d] ", vector[i]);
    }
    printf("\n");
}

int *MultMat ( int *vma, int *vmb, int n, int m, int p, int q) {
    if (m != p) {
        printf("error: number of columns in the first matrix different from the number of rows in the second matrix.\n");
        return NULL;
    }

    int result_rows = n;
    int result_columns = q;
    int *result = (int *) malloc(sizeof(int) * result_rows * result_columns);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float result_element = 0;
            for (int k = 0; k < m; ++k) {
                result_element += vma[i * m + k] * vmb[k * q + j];
            }
            result[i * result_columns + j] = result_element;
        }
    }

    return result;
}

int main() {
    int n = 2, m = 3, p = 3, q = 2;

    int *matrix_a = allocate_vector(n*m);
    int *matrix_b = allocate_vector(p*q);

    matrix_a = random_vector(matrix_a, n*m, 5);
    matrix_b = random_vector(matrix_b, p*q, 5);

    view_vector(matrix_a, n*m);
    view_vector(matrix_b, p*q);
    view_vector(MultMat(matrix_a, matrix_b, n, m, p, q), n*q);

    return 0;
}
