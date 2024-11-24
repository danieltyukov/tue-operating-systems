#include <stdio.h>

void set_negatives_to_zero(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            array[i] = 0;
        }
    }
}

int main() {
    int array[] = {5, -3, 8, -1, 7};
    int size = sizeof(array) / sizeof(array[0]);

    // Print in reverse using subscript
    printf("Reverse order using subscript:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Print in reverse using pointer
    printf("Reverse order using pointer:\n");
    int *ptr = &array[size - 1];
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", *ptr--);
    }
    printf("\n");

    // Set negative values to zero
    set_negatives_to_zero(array, size);

    // Print the modified array
    printf("Modified array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
