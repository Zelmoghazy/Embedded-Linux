#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for fork()
#include <sys/wait.h> // for wait()

int main(void) 
{
    pid_t pid;
    // Create a new process using fork()
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // This is the child process
        printf("Child Process: My PID is %d\n", getpid());
        printf("Child Process: My Parent PID is %d\n", getppid());
        printf("Child Process: Doing some work...\n");
        sleep(2);  // Simulate some work
        printf("Child Process: Work done. Exiting...\n");
    } else {
        // This is the parent process
        printf("Parent Process: My PID is %d\n", getpid());
        printf("Parent Process: My Child's PID is %d\n", pid);
        printf("Parent Process: Waiting for child to finish...\n");
        wait(NULL); // Wait for child process to finish
        printf("Parent Process: Child finished. Exiting...\n");
    }
    return 0;
}
