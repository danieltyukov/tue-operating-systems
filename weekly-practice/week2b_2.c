#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void calculate_primes(bool *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = true;
    }
    array[0] = array[1] = false;
    for (int i = 2; i * i < size; i++) {
        if (array[i]) {
            for (int j = i * i; j < size; j += i) {
                array[j] = false;
            }
        }
    }
}

int main() {
    int size = 20;
    bool primes[size];

    calculate_primes(primes, size);

    printf("Prime numbers up to %d:\n", size - 1);
    for (int i = 0; i < size; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
