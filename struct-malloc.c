#include <stdio.h>
#include <stdlib.h>

// Define a struct for a Student
typedef struct student {
    int nbr; // Student number
    struct student *next; // Pointer to the next student in the list
} Student;

int main() {
    // Create the first Student node
    Student a;
    a.nbr = 73;
    a.next = NULL;

    // Create a pointer to a Student and assign it to the first node
    Student *b = &a;
    b->nbr = 43;

    // Dynamically allocate memory for a second Student
    Student *c = (Student *)malloc(sizeof(Student));
    if (c == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    c->nbr = 25;
    a.next = c;

    // Dynamically allocate memory for a third Student
    Student *d = (Student *)malloc(sizeof(Student));
    if (d == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    d->nbr = 12;
    c->next = d;
    d->next = NULL;

    // Print the list
    printf("Student List:\n");
    Student *current = &a;
    while (current != NULL) {
        printf("Student number: %d\n", current->nbr);
        current = current->next;
    }

    // Remove the second element (c)
    a.next = c->next;
    free(c);

    // Print the updated list
    printf("\nUpdated Student List:\n");
    current = &a;
    while (current != NULL) {
        printf("Student number: %d\n", current->nbr);
        current = current->next;
    }

    // Free remaining dynamically allocated memory
    free(d);

    return 0;
}
