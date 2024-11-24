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
            A();
            wait(NULL);
            B();
            wait(NULL);
            D();
            printf("workload processed.\n");
        } else {
            C();
        }
    } else {
        E();
    }

    return 0;
}