#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void record_execution(const char *function_name) {
    int fd = open("execution_order.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd >= 0) {
        dprintf(fd, "%s executed\n", function_name);
        close(fd);
    }
}

void A() {
    printf("A completed \n");
    record_execution("A");
}
void B() {
    printf("B completed \n");
    record_execution("B");
}
void C() {
    printf("C completed \n");
    record_execution("C");
}
void D() {
    printf("D completed \n");
    record_execution("D");
}
void E() {
    printf("E completed \n");
    record_execution("E");
}

int main() {
    int status;
    pid_t idC, idE;

    // Remove existing execution_order.txt file
    remove("execution_order.txt");

    idE = fork();

    if (idE > 0) {
        idC = fork();

        if (idC > 0) {
            waitpid(idC, &status, 0); // Wait for idC to finish
            A();
            B();
            D();
            wait(NULL); // Wait for idE to finish
            printf("Workload processed.\n");
        } else {   
            C();   
        }
    } else {   
        E();  
    }

    return 0;
}

// The first fork() creates a child process (idE) from the main process. The child process will execute the code in the else branch (E()), while the parent process continues executing after the if block.
// In the parent process, the second fork() creates another child process (idC). The child process of this fork() will execute C().