#include <stdio.h>
#include <stdlib.h>

//question 01
int get_higher_value(int *p_vector, int n) {
    int higher_value = p_vector[0];

    for (int i = 0; i < n; i++) {
      if (p_vector[i] > higher_value) higher_value = p_vector[i];
    }

    return higher_value;
}

int get_sum_values(int *p_vector, int n) {
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += p_vector[i];
  }

  return sum;
}

int get_middle_value(int *p_vector, int n) {
  int middle_index = ceil(n/2);
  return p_vector[middle_index];
}

int main() {
    int n;
    scanf("%d", &n);
  
    int *p_vector = (int*) malloc(n * sizeof (int));

    for (int i = 0; i < n; i++) {
      scanf("%d", &p_vector[i]);
    }

    //maior valor
    int higher_value = get_higher_value(p_vector, n);
    printf("higher value: %d\n", higher_value);

    //soma dos números
    int sum = get_sum_values(p_vector, n);
    printf("sum of values: %d\n", sum);

    //elemento do meio
    int middle_value = get_middle_value(p_vector, n);
    printf("middle element: %d\n", middle_value);
}
