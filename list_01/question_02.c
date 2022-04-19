#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//question 02

int main() {
    int n;
    scanf("%d", &n);
    float vector[n];

    for (int i = 0; i < n; ++i) {
        vector[i] = rand() % 10;
    }

    for (int i = 0; i < n; ++i) {
        printf("[%f] ", vector[i]);
    }
    printf("\n");

    float higher_value = vector[0];
    for (int i = 0; i < n; ++i) {
        if (vector[i] > higher_value) {
            higher_value = vector[i];
        }
    }

    printf("higher value: %f\n", higher_value);

    float sum_values = 0;
    for (int i = 0; i < n; ++i) {
        sum_values += vector[i];
    }

    printf("sum of values: %f\n", sum_values);

    int ceil_of = ceil((float)n/2);
    int floor_of = floor((float)n/2);
    int round_of = round((float)n/2);

    printf("%d, %d, %d\n",  ceil_of, floor_of, round_of);

    printf("element of vector[ceil[n/2]]: %f\n", vector[ceil_of]);
    printf("element of vector[floor[n/2]]: %f\n", vector[floor_of]);
    printf("element of vector[round[n/2]]: %f\n", vector[round_of]);

    return 0;
}