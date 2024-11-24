#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void f() {
    pid_t p = fork(); 
    if (p == 0) {
        // Child process
        printf("Child process: PID=%d, PPID=%d\n", getpid(), getppid());
        f();
    } else if (p > 0) {
        // Parent process
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), p);
        waitpid(p, NULL, 0);
        printf("Parent process: PID=%d resumed after waiting for PID=%d\n", getpid(), p);
    } else {
        perror("fork");
    }
}

int main() {
    f();
    return 0;
}