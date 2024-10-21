// writer.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char *fifo_path = "my_fifo";  // FIFO file path
    char message[] = "Hello from the writer process!\n";

    // Open FIFO for writing only
    fd = open(fifo_path, O_WRONLY);

    // Write to the FIFO
    write(fd, message, strlen(message) + 1);

    // Close the FIFO
    close(fd);

    return 0;
}
