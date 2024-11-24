#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int i = 17;

int main() {
    pid_t id;
    id = fork();

    if (id == 0) { 
        execlp("/bin/sh", "/bin/sh", "-c", "ls -l /bin/??", (char *)NULL); 
    } 

    if (id > 0 ) { 
        fork(); 
    }

    i = i + 8;

    printf("The value of i is: %d\n", i);

    return 0;
}