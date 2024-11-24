#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the PARENT structure
typedef struct {
    char name[50];
    int age;
} PARENT;

// Define the CHILD structure
typedef struct {
    PARENT *father;
    PARENT *mother;
    char name[50];
    int age;
} CHILD;

int main() {
    // Allocate memory for one child
    CHILD *child = (CHILD *)malloc(sizeof(CHILD));
    if (child == NULL) {
        printf("Memory allocation failed for child\n");
        return 1;
    }

    // Allocate memory for two parents
    child->father = (PARENT *)malloc(sizeof(PARENT));
    child->mother = (PARENT *)malloc(sizeof(PARENT));
    if (child->father == NULL || child->mother == NULL) {
        printf("Memory allocation failed for parents\n");
        free(child);
        return 1;
    }

    // Assign values to the father's members
    strcpy(child->father->name, "John");
    child->father->age = 40;

    // Assign values to the mother's members
    strcpy(child->mother->name, "Jane");
    child->mother->age = 38;

    // Assign values to the child's members
    strcpy(child->name, "Alice");
    child->age = 10;

    // Print the contents of all structures
    printf("Child:\n");
    printf("  Name: %s\n", child->name);
    printf("  Age: %d\n", child->age);
    printf("Father:\n");
    printf("  Name: %s\n", child->father->name);
    printf("  Age: %d\n", child->father->age);
    printf("Mother:\n");
    printf("  Name: %s\n", child->mother->name);
    printf("  Age: %d\n", child->mother->age);

    // Free the allocated memory
    free(child->father);
    free(child->mother);
    free(child);

    return 0;
}
