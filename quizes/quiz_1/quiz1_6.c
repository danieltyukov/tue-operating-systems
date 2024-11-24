#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void A() {
    printf("A completed by PID %d\n", getpid());
}

void B() {
    printf("B completed by PID %d\n", getpid());
}

void C() {
    printf("C completed by PID %d\n", getpid());
}

void D() {
    printf("D completed by PID %d\n", getpid());
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        A();
        execlp("/bin/sh", "/bin/sh", "-c", "ls -l /bin/??", (char *)NULL);
        // If execlp fails
        perror("execlp failed");
        _exit(1);
    } else if (pid > 0) {
        // Parent process
        B();
    } else {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    C();

    if (pid > 0) {
        // Parent process waits for child
        wait(NULL);
    }

    D();

    return 0;
}