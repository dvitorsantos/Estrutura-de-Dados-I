#include <stdio.h>

//question 01

#define ROWS 3
#define COLUMNS 4

float vector[ROWS] = {4, 9, 10};
float matrix[ROWS][COLUMNS] = { 4, 2, 3, 4,
                               5, 6, 7, 8,
                               9, 10, 11, 12};

void ElementoVetorEMatriz ( int n, int m, float *vetor, float **matriz) {
   for (int i = 0; i < n; ++i) {
       float vector_element = vetor[i];
       for (int j = 0; j < n; ++j) {
           for (int k = 0; k < m; ++k) {
               float matrix_element = *(*(matrix + j) + k);
               if (vector_element == matrix_element) {
                   printf("vector[%d] == matrix[%d][%d] == %f\n", i, j, k, vector_element);
               }
           }
       }
   }
}

int main() {
   ElementoVetorEMatriz(ROWS, COLUMNS, vector, matrix);
   return 0;
}