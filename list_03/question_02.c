//question 02

#include <stdio.h>
#include <stdlib.h>

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

float **random_matrix(float **matrix, int rows, int columns, int range) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = rand() % range;
        }
    }
    return matrix;
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

**MultMatrix ( int n, int m, float **ma, int p, int q, float **mb) {

    if (m != p) {
        printf("error: number of columns in the first matrix different from the number of rows in the second matrix.\n");
        return NULL;
    }

    int result_rows = n;
    int result_columns = q;
    float **result_matrix;

    result_matrix = (float **) malloc(sizeof(float *) * result_rows);

    if (result_matrix != NULL) {
        for (int i = 0; i < result_rows; i++) {
            result_matrix[i] = (float *) malloc(sizeof(float) * result_columns);
            if (result_matrix[i] == NULL) {
                for (int j = i - 1; j > 0; j--) {
                    free(result_matrix[i]);
                }
                free(result_matrix);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float result_element = 0;
            for (int k = 0; k < m; ++k) {
                result_element += ma[i][k] * mb[k][j];
            }
            result_matrix[i][j] = result_element;
        }
    }

    return result_matrix;
}

int main() {
    int n = 2, m = 3, p = 3, q = 2;
    float **ma, **mb;

    ma = allocate_matrix(n, m);
    mb = allocate_matrix(p, q);

    ma = random_matrix(ma, n, m, 10);
    mb = random_matrix(mb, p, q, 10);

    float **result = MultMatrix( n, m, ma, p, q, mb);

    view_matrix(ma, n, m);
    view_matrix(mb, p, q);
    view_matrix(result, n, q);

    return 0;
}