#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LEN 3
#define ALPHABET_START_CHAR 'a'
#define ALPHABET_END_CHAR 'z'

void printCharArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Character at index %d: %c\n", i, arr[i]);
    }
}

int main() {
    // 1. Declaring and initializing strings
    char s1[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char s2[10] = "bike";

    printf("String s1: %s\n", s1);
    printf("String s2: %s\n", s2);

    // 2. Modifying strings
    strcpy(s1, "car");
    printf("Modified s1 using strcpy: %s\n", s1);

    s1[3] = 'd';
    printf("Modified s1 manually: %s\n", s1);

    // 3. String length and size
    int len = strlen(s1);
    int size = sizeof(s1);
    printf("Length of s1 (strlen): %d, Size of s1 (sizeof): %d\n", len, size);

    // 4. Generating a key within MAX_MESSAGE_LEN
    char key[MAX_MESSAGE_LEN + 1] = {'a', 'b', 'c', '\0'};
    printf("Initial key: %s\n", key);

    key[2] = 'd'; // Incrementing last character
    printf("Next key: %s\n", key);

    // 5. Handling arrays as characters
    char charArray[5] = {'A', 'B', 'C', 'D', '\0'};
    printf("Character array: %s\n", charArray);
    printCharArray(charArray, 4);

    // 6. Edge case: Handling ALPHABET_END_CHAR
    char message[MAX_MESSAGE_LEN + 1] = "xyz";
    int len_message = strlen(message);
    if (message[len_message - 1] == ALPHABET_END_CHAR) {
        printf("Last character is ALPHABET_END_CHAR\n");
        message[len_message - 1] = '\0'; // Null-terminate earlier
    } else {
        printf("Message does not end with ALPHABET_END_CHAR\n");
    }
    printf("Final message: %s\n", message);

    return 0;
}
