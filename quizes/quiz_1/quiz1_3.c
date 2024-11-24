#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i = 0;
    pid_t pid;
    int zombie_count = 0;

    for (int k = 0; k < 5; ++k) {
        pid = fork();
        if (pid == 0) {
            // Child process
            execlp("/bin/sh", "/bin/sh", "-c", "ls -l /bin/??", (char *)NULL);
            // If execlp fails
            _exit(1);
        } else if (pid > 0) {
            // Parent process does not wait for child
            // Child will become zombie after it exits
            zombie_count++;
        } else {
            // Fork failed
            perror("fork failed");
            return 1;
        }
    }

    // Sleep to allow children to finish
    sleep(1);

    // Print the number of zombie processes
    printf("Total number of zombie processes: %d\n", zombie_count);

    // Wait for all child processes to clean up zombies
    for (int k = 0; k < 5; ++k) {
        wait(NULL);
    }

    i++;
    return 0;
}