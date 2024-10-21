#include <stdio.h>
#include <stdlib.h>

/*
    The  popen()  function  opens a process by creating a pipe, forking, and invoking the shell.

    The return value from popen() is a normal standard I/O  stream  in  all  respects
    save that it must be closed with pclose() rather than fclose(3).
    Writing to such a stream writes to the standard input of the command;
    the command's standard output  is  the  same as that of the process that called popen()
 */


int main() {
    FILE *fp;
    char path[1035];

    // Open the command for reading
    fp = popen("ls -l", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    // Read the output a line at a time and print it to the screen
    while (fgets(path, sizeof(path), fp) != NULL) {
        printf("%s", path);
    }

    // Close the pipe
    pclose(fp);

    return 0;
}
