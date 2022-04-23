//question 04

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

float *random_vector(float *vector, int size, int range) {
    for (int i = 0; i < size; ++i) {
        vector[i] = rand() % range;
    }
    return vector;
}

void view_vector(float *vector, int size) {
    for (int i = 0; i < size; ++i) {
        printf(" [%f] ", vector[i]);
    }
    printf("\n");
}

float *MultMatEmVetor(int n, int m, int p, int q, float *vma, float *vmb) {

    if (m != p) {
        printf("error: number of columns in the first matrix different from the number of rows in the second matrix.\n");
        return NULL;
    }

    int result_rows = n;
    int result_columns = q;
    float *result;

    result = (float *) malloc(sizeof(float) * result_rows * result_columns);

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
    float *vector_matrix_a, *vector_matrix_b;
    int vector_matrix_size_a = n * m;
    int vector_matrix_size_b = p * q;

    vector_matrix_a = allocate_vector(vector_matrix_size_a);
    vector_matrix_b = allocate_vector(vector_matrix_size_b);

    vector_matrix_a = random_vector(vector_matrix_a, vector_matrix_size_a, 10);
    vector_matrix_b = random_vector(vector_matrix_b, vector_matrix_size_b, 10);

    float *result = MultMatEmVetor(n, m, p, q, vector_matrix_a, vector_matrix_b);

    view_vector(vector_matrix_a, vector_matrix_size_a);
    view_vector(vector_matrix_b, vector_matrix_size_b);
    view_vector(result, n * q);
}