#include <stdio.h>

// Function that modifies a value using pointers
void addFive(int *v) {
    *v = *v + 5;
}

void incorrectAddFive(int v) {
    v = v + 5;
}

int main() {
    // Example 1: Simple pass-by-value vs pass-by-reference
    int z = 20;

    // Incorrect example: Passing by value
    incorrectAddFive(z);
    printf("Pass-by-value: z = %d (unchanged)\n", z);

    // Correct example: Passing by reference
    addFive(&z);
    printf("Pass-by-reference: z = %d (modified)\n", z);

    // Example 2: Basic pointer declaration and memory location
    int i = 12, j = 34;
    int *p = &i, *q = &j;

    printf("Memory address of i: %p, j: %p\n", (void *)&i, (void *)&j);
    printf("Pointer p points to: %p, *p = %d\n", (void *)p, *p);

    // Example 3: Pointer assignment and modification
    *p = 56;
    printf("Modified i via *p: i = %d\n", i);

    // Example 4: Arithmetic with pointers
    int k = *p + 7;
    printf("Arithmetic on pointer: k = %d\n", k);

    // Example 5: Pointer-to-pointer and swapping
    int **pp = &p;
    printf("Pointer-to-pointer: **pp = %d\n", **pp);

    // Swapping pointers
    printf("Before swap: *p = %d, *q = %d\n", *p, *q);
    int *temp = p;
    p = q;
    q = temp;
    printf("After swap: *p = %d, *q = %d\n", *p, *q);

    // Example 6: Pointer increment (array traversal)
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    printf("Array elements using pointer arithmetic:\n");
    for (int idx = 0; idx < 5; idx++) {
        printf("arr[%d] = %d\n", idx, *ptr);
        ptr++;
    }

    // Example 7: Uninitialized pointers (dangerous practice)
    int *uninitialized_ptr;
    printf("Uninitialized pointer: %p (undefined behavior!)\n", (void *)uninitialized_ptr);

    // Proper NULL initialization
    int *safe_ptr = NULL;
    if (safe_ptr == NULL) {
        printf("Safe pointer handling: Pointer is NULL.\n");
    }

    return 0;
}
