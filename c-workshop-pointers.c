#include <stdio.h>

// Function to add 5 to the value at the pointer
void addFive(int *v) {
    *v += 5;
}

// Function demonstrating swapping using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Basic pointer example
    int x = 10, y = 20, z;
    int *px = &x, *py = &y;

    printf("Before addition: x = %d, y = %d\n", x, y);

    // Passing pointer to function
    addFive(px);
    addFive(py);

    printf("After addition: x = %d, y = %d\n", x, y);

    // Swapping values using pointers
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(px, py);
    printf("After swap: x = %d, y = %d\n", x, y);

    // Demonstrating pointer arithmetic
    z = *px + *py;
    printf("Sum of *px and *py: z = %d\n", z);

    // Pointer increment example
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;

    printf("Array elements using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, *p);
        p++;
    }

    // Caution: uninitialized pointer (example of bad practice)
    int *t = NULL; // Initialize to NULL to prevent undefined behavior
    if (t == NULL) {
        printf("Pointer 't' is NULL, safe to use with conditions.\n");
    }

    return 0;
}
