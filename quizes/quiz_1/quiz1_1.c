#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
    pid_t smith;
    pid_t initial_pid = getpid();

    // Create shared memory segment
    int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    int *process_count = (int *)shmat(shm_id, NULL, 0);
    *process_count = 1; // Initial process

    smith = fork();
    if (smith == 0) {
        // Child process
        (*process_count)++;
    }

    for (int j = 0; j < 3; j++) {
        if (smith == 0) {
            smith = fork();
            if (smith == 0) {
                (*process_count)++;
            } else if (smith > 0) {
                wait(NULL);
            }
        }
    }

    for (int k = 0; k < 2; k++) {
        if (smith > 0) {
            smith = fork();
            if (smith == 0) {
                (*process_count)++;
            } else if (smith > 0) {
                wait(NULL);
            }
        }
    }

    // Wait for all child processes to finish
    while (wait(NULL) > 0);

    if (getpid() == initial_pid) {
        printf("Total number of Agent_Smith processes: %d\n", *process_count);
        // Detach and remove shared memory
        shmdt(process_count);
        shmctl(shm_id, IPC_RMID, NULL);
    } else {
        // Detach shared memory in child processes
        shmdt(process_count);
    }

    return 0;
}