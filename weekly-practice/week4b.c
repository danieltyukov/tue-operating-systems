#include <stdio.h>
#include <stdlib.h>

// Function to print the binary representation of an integer
void to_binary(int num) {
    printf("0b");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to create a bitmask with a given width and shift
char* create_bitmask(int width, int shift) {
    int bitmask = ((1 << width) - 1) << shift;
    int total_bits = sizeof(int) * 8;
    char* result = (char*)malloc(total_bits + 3); // +3 for "0b" and null terminator

    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    result[0] = '0';
    result[1] = 'b';
    for (int i = 0; i < total_bits; i++) {
        result[i + 2] = ((bitmask >> (total_bits - 1 - i)) & 1) ? '1' : '0';
    }
    result[total_bits + 2] = '\0';

    return result;
}

int main() {
    // Test to_binary function
    int num = 73;
    printf("Binary representation of %d: ", num);
    to_binary(num);

    // Test create_bitmask function
    int width = 5;
    int shift = 1;
    char* bitmask = create_bitmask(width, shift);
    if (bitmask != NULL) {
        printf("Bitmask with width %d and shift %d: %s\n", width, shift, bitmask);
        free(bitmask);
    } else {
        printf("Memory allocation failed for bitmask.\n");
    }

    return 0;
}
