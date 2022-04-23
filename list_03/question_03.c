//question 03

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

int *RetornaElementosdaLinhal ( int *vm, int n, int m, int l ) {
    int *result;

    result = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        int index = l * m + i;
        result[i] = vm[index];
    }

    return result;
}

int main() {
    int n = 2, m = 3, l = 0;
    int vector_matrix_size = n*m;
    int *vector_matrix;

    vector_matrix = allocate_vector(vector_matrix_size);
    vector_matrix = random_vector(vector_matrix, vector_matrix_size, 10);
    int *result = RetornaElementosdaLinhal(vector_matrix, n, m, l);
    view_vector(result, n);

    return 0;
}