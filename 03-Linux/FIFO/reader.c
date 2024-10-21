// reader.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *fifo_path = "my_fifo";  // FIFO file path
    char buffer[100];

    // Open FIFO for reading only
    fd = open(fifo_path, O_RDONLY);

    // Read from the FIFO
    read(fd, buffer, sizeof(buffer));

    // Print the received message
    printf("Received: %s\n", buffer);

    // Close the FIFO
    close(fd);

    return 0;
}
