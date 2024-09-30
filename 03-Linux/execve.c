#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is about to execute /bin/ls\n", getpid());

        char *args[] = {"/bin/ls", "-l", "/home", NULL};
        char *env[] = {NULL};

        if (execve("/bin/ls", args, env) == -1) {
            perror("execve");
            exit(1);
        }

        // This line will not be reached if execve is successful
        printf("This line will not be printed in the child process\n");
    } else {
        // Parent process
        printf("Parent process (PID: %d) created child (PID: %d)\n", getpid(), pid);
        
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit normally\n");
        }
    }

    return 0;
}