#include <stdio.h>
#include <stdint.h>

// Macros for bit operations
#define BITMASK(n)       (1U << (n))
#define BIT_SET(v, n)    ((v) | BITMASK(n))
#define BIT_CLEAR(v, n)  ((v) & ~BITMASK(n))
#define BIT_TOGGLE(v, n) ((v) ^ BITMASK(n))
#define BIT_IS_SET(v, n) (((v) & BITMASK(n)) != 0)

// Function to display binary representation of an integer
void print_binary(uint32_t num) {
    for (int i = 31; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    uint32_t number = 229; // Example number
    printf("Original number: %u\n", number);
    printf("Binary: ");
    print_binary(number);

    // Set bit 3
    number = BIT_SET(number, 3);
    printf("\nAfter setting bit 3: %u\n", number);
    print_binary(number);

    // Clear bit 7
    number = BIT_CLEAR(number, 7);
    printf("\nAfter clearing bit 7: %u\n", number);
    print_binary(number);

    // Toggle bit 5
    number = BIT_TOGGLE(number, 5);
    printf("\nAfter toggling bit 5: %u\n", number);
    print_binary(number);

    // Check if bit 3 is set
    printf("\nIs bit 3 set? %s\n", BIT_IS_SET(number, 3) ? "Yes" : "No");

    // Invert all bits
    number = ~number;
    printf("\nAfter inverting all bits: %u\n", number);
    print_binary(number);

    return 0;
}
