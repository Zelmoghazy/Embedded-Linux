#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>


/*
    The problem with pipes is that they are usable only between 
    processes that have a common ancestor (i.e., a parent-child relationship),
    but this was fixed with the introduction of named pipes or FIFOs 
 */

int main(void) 
{
    int fd[2];  // Array for pipe file descriptors: fd[0] for reading, fd[1] for writing
    pid_t pid;  // To store the forked process ID
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    // Create the pipe
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]);  // Close the reading end

        // Write to the pipe
        write(fd[1], write_msg, strlen(write_msg) + 1);

        // Close the writing end
        close(fd[1]);

        // Wait for the child to complete
        wait(NULL);
    } else {
        // Child process
        close(fd[1]);  // Close the writing end

        // Read from the pipe
        read(fd[0], read_msg, sizeof(read_msg));

        // Print the received message
        printf("Child received: %s\n", read_msg);

        // Close the reading end
        close(fd[0]);
    }

    return 0;
}
