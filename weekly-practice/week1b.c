#include <stdio.h>

/* Function prototypes */
void add_and_multi_with_4_parameters(int a, int b, int *sum, int *product);
void add_and_multi_with_2_parameters(int a, int b, int *sum_and_product);

int main() {
    /* Exercise 3: Pointer basics */
    int *pc;
    int c;

    c = 73;
    printf("Address of c: %p\n", (void *)&c);
    printf("Value of c: %d\n\n", c);

    pc = &c;
    printf("Address of pointer pc: %p\n", (void *)pc);
    printf("Content of pointer pc: %d\n\n", *pc);

    c = 42;
    printf("Address of pointer pc: %p\n", (void *)pc);
    printf("Content of pointer pc: %d\n\n", *pc);

    *pc = 1000;
    printf("Address of c: %p\n", (void *)&c);
    printf("Value of c: %d\n\n", c);

    /* Exercise 4: Extended pointer manipulation */
    int d;
    int *q = &d;
    int *z;

    *q = 500;
    printf("Address of d: %p, Value of d: %d\n", (void *)&d, d);
    printf("Address of pointer q: %p, Content of pointer q: %d\n\n", (void *)q, *q);

    pc = &c;
    *pc = *q;
    printf("Value of c after *pc = *q: %d\n\n", c);

    *q = *pc;
    printf("Value of d after *q = *pc: %d\n\n", d);

    q = pc;
    printf("Address of pointer q after q = pc: %p, Value at q: %d\n\n", (void *)q, *q);

    // Uncommenting the following lines will cause undefined behavior:
    // q = *pc; // Assigning an int to a pointer (incorrect)
    // *q = pc; // Assigning a pointer to an int (incorrect)
    // *z = 2000; // Dereferencing an uninitialized pointer (undefined behavior)

    /* Exercise 5: Parameter passing via pointers */
    int sum, product, combined;

    add_and_multi_with_4_parameters(5, 10, &sum, &product);
    printf("Using add_and_multi_with_4_parameters:\n");
    printf("Sum: %d, Product: %d\n\n", sum, product);

    add_and_multi_with_2_parameters(5, 10, &combined);
    printf("Using add_and_multi_with_2_parameters:\n");
    printf("Sum and Product (stored together): %d\n", combined);

    return 0;
}

/* Function definitions */
void add_and_multi_with_4_parameters(int a, int b, int *sum, int *product) {
    *sum = a + b;
    *product = a * b;
}

void add_and_multi_with_2_parameters(int a, int b, int *sum_and_product) {
    *sum_and_product = a + b + a * b; // Combined representation
}
