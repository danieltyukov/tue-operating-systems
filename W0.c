#include <stdio.h>
#include <stdlib.h> // Include this header for malloc and free

int main(int argc, char * argv[])
{
    // basic printing function
    printf("Hello world\n");

    int n = 33;
    int m = 57;

    // printing with data
    printf("values %d and %d\n", m, n);
    // printing in the error channel (useful for debugging)
    fprintf(stderr, "erroutput\n");

    // for loops and if statements
    for (int i = 0; i < 5; i++)
    {
        if(i > 3){
            printf("loop%d\n", i);
        }
    }

    // declaring arrays
    int a1[10];
    int a2[4];

    // C is fine with you reading uninitialised values
    printf("value: %d\n", a1[8]);

    // filling the arrays
    // note that a2 is filled beyond its index, but that is fine for C
    for (int i = 0; i < 4; i++) // Corrected the loop to avoid out-of-bounds access
    {
        a1[i] = 44;
        a2[i] = 10-i;
    }

    // by printing the values, you can see that a1 has been partially overwritten by out of index values for a2
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");

    // strings are defined as character arrays
    // the end of a string is marked with "\0", which is added implicitly
    char s1[8] = "tes\0t1";
    char s2[8] = "test2";

    printf("strings %s and %s\n", s1, s2);

    for(int i = 0; i < 8; i++) // Corrected the loop to avoid out-of-bounds access
    {
        printf("%c ", s1[i]);
    }
    printf("\n");
    for(int i = 0; i < 8; i++) // Corrected the loop to avoid out-of-bounds access
    {
        printf("%c ", s2[i]);
    }
    printf("\n");

    // in C, you can print the address of a variable in memory
    // a variable that holds an address is called a pointer
    printf("address: %p\n", (void*)&s1[0]);
    printf("address: %p\n", (void*)&s1[1]);
    // actually, arrays are pointers (to the first element in the array)
    printf("address: %p\n", (void*)s1);
    // you can use pointer arithmetic instead of array indexing
    printf("address: %p\n", (void*)(s1 + 1));

    // note that pointer arithmetic takes into account the size of the data type
    int a[3] = {44, 55, 66};

    printf("address: %p\n", (void*)&a[0]);
    printf("address: %p\n", (void*)&a[1]);
    printf("address: %p\n", (void*)a);
    printf("address: %p\n", (void*)(a + 1));

    // some sizes of data types
    printf("size: %ld\n", sizeof(char));
    printf("size: %ld\n", sizeof(int));
    printf("size: %ld\n", sizeof(unsigned long));

    // to allocate memory with a size that depends on variables, use malloc
    int k = 77;

    // this allocates space for k integers, and return a pointer to the first element
    int *p = malloc(k*sizeof(int));

    // use *p in an expression to refer to the value at the address that pointer p is pointing to
    // you can use this to assign a value at the address
    *p = 8;
    *(p+1) = 46;

    // or to read the value at the address
    printf("value: %d\n", *(p+1)); // Added newline for better formatting

    // when a declared variable runs out of scope of the program, its memory is deallocated automatically
    // but for malloc you need to deallocate it yourself
    // for this you should use free
    free(p);

    return 0; // Added return statement
}
