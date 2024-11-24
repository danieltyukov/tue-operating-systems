#include <stdio.h>
#include <stdbool.h>

// Function to set all negative values in an array to zero
void set_negatives_to_zero(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            array[i] = 0;
        }
    }
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// Function to calculate prime values and set the boolean array
void calculate_primes(bool *prime_array, int size) {
    for (int i = 0; i < size; i++) {
        prime_array[i] = is_prime(i);
    }
}

int main() {
    // Analyze and execute interprocess_basics.c
    printf("Running interprocess_basics.c...\n");
    system("gcc interprocess_basics.c -o interprocess_basics && ./interprocess_basics");

    // Exercise 7: Arrays of integers
    int integer_array[] = {3, -1, 4, -5, 2, -9};
    int size = sizeof(integer_array) / sizeof(integer_array[0]);

    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", integer_array[i]);
    }

    printf("\nArray in reverse (using subscript): ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", integer_array[i]);
    }

    printf("\nArray in reverse (using pointer): ");
    for (int *ptr = &integer_array[size - 1]; ptr >= integer_array; ptr--) {
        printf("%d ", *ptr);
    }

    set_negatives_to_zero(integer_array, size);
    printf("\nArray after setting negatives to zero: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", integer_array[i]);
    }

    // Exercise 8: Arrays of booleans
    const int bool_array_size = 20;
    bool prime_array[bool_array_size];
    calculate_primes(prime_array, bool_array_size);

    printf("\n\nBoolean array (prime numbers):\n");
    for (int i = 0; i < bool_array_size; i++) {
        printf("Index %d: %s\n", i, prime_array[i] ? "true" : "false");
    }

    return 0;
}
