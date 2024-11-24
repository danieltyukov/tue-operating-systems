#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void A() { printf("A completed\n"); }
void B() { printf("B completed\n"); }
void C() { printf("C completed\n"); }
void D() { printf("D completed\n"); }
void E() { printf("E completed\n"); }

int main() {
    int status;

    pid_t pid1, pid2, pid3;

    // Create the first process to handle A and B
    pid1 = fork();
    if (pid1 == 0) {
        // Child process for A and B
        A();
        B();
        exit(0);
    }

    // Create the second process to handle C
    pid2 = fork();
    if (pid2 == 0) {
        // Child process for C
        C();
        exit(0);
    }

    // Wait for processes handling A, B, and C
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);

    // Create the third process to handle D and E
    pid3 = fork();
    if (pid3 == 0) {
        // Child process for D and E
        D();
        E();
        exit(0);
    }

    // Wait for the last process to complete
    waitpid(pid3, &status, 0);

    return 0;
}
