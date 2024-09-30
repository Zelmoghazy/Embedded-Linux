#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>

#define MAX_LINE     80  // The maximum length of a command
#define HIST_LEN     32  // Remember last 32 commands  


struct termios orig_term;

typedef struct ring_buffer_t
{
    uint32_t write_idx;    
    uint32_t used;
    uint32_t mask;
    char     buffer[HIST_LEN][MAX_LINE];
}ring_buffer_t;

void rb_write(ring_buffer_t *rb, char *cmd)
{
	strcpy(rb->buffer[rb->write_idx],cmd);
    // cool trick but size must be power of two for it to work
	rb->write_idx = (rb->write_idx +1) & rb->mask;
    if(rb->used < HIST_LEN){
        rb->used++;
    }
}

void rb_read(ring_buffer_t *rb)
{
    // Start from the last executed command
    int read_idx = rb->write_idx-1;

    // iterate over all commands in history
    for(size_t i = 0; i < rb->used; i++)
    {
        // cannot do the cool "and" trick as 
        // commands the user typed are not neccessarily power of two
        if(read_idx==-1){
            read_idx= HIST_LEN-1;
        }
        fprintf(stdout,"%s",rb->buffer[read_idx]);
        read_idx--;
    }
}

// Function to split the command into arguments
void parseCommand(char *input, char **args) 
{
    for (int i = 0; i < MAX_LINE / 2 + 1; i++) {
        args[i] = strsep(&input, " \t\r\n"); // Split input into tokens
        // Skip empty arguments (caused by multiple spaces/tabs)
        if (args[i] == NULL || strlen(args[i]) == 0) {
            args[i] = NULL;
            break;
        }
    }
}
void disableRawMode() 
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_term);
}

void enableRawMode() 
{
    // Make a copy of terminal attributes before entering raw mode
    tcgetattr(STDIN_FILENO, &orig_term);
    // called automatically when the program exits
    atexit(disableRawMode);

    struct termios term;
    tcgetattr(STDIN_FILENO, &term);

    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}


void moveCursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

void clearScreen() {
    printf("\033[2J");
}

int main(void)
{
    char *args[MAX_LINE / 2 + 1];  // Command line arguments
    char input[MAX_LINE];          // Input command

    pid_t pid;
    int running = 1;            // Flag to determine when to exit the program


    ring_buffer_t rb;
	rb.write_idx    = 0;
	rb.mask         = HIST_LEN-1;		// size must be power of 2

#ifndef SIMPLE
    int i = 0;
    int c;
    int row = 1, col = 1;

    enableRawMode();
#endif    

    while (running) 
    {
        printf("zeyad> ");

#ifdef SIMPLE
        // Get user input
        if (fgets(input, MAX_LINE, stdin) == NULL) {
            perror("fgets failed");
            exit(EXIT_FAILURE);
        }
#else
        i = 0;

        while ((c = getchar()) != '\n' && c != EOF) {
            //
            if (c == 27) {  // ESC key (beginning of an escape sequence)
                c = getchar();
                if (c == '[') {  // Second part of escape sequence
                    c = getchar();
                    if (c == 'A') {
                        strcpy(input,rb.buffer[rb.write_idx-1]);
                        fprintf(stdout,"%s",input);
                        i = strlen(rb.buffer[rb.write_idx-1])+1;
                        continue;
                    } else if (c == 'B') {
                        printf("↓");
                        continue;
                    } else if (c == 'C') { // Right arrow
                        col++;
                        moveCursor(row, col);
                    } else if (c == 'D') { // Left arrow
                        if (col > 1) col--;
                        moveCursor(row, col);
                    }
                }
                continue;
            }
            if (i < MAX_LINE - 1) {
                input[i++] = c;
                fprintf(stdout,"%c",c);
            }
        }
        fprintf(stdout,"\n");

        input[i] = '\0'; // Null-terminate the string

        if (c == EOF && i == 0) {
            perror("getchar failed or no input");
            exit(EXIT_FAILURE);
        }
#endif

        // If the user types "exit", terminate the shell

        if (strncmp(input, "exit", 4) == 0) {
            running = 0;
            continue;
        }

        if (strncmp(input, "hist", 4) == 0) {
            rb_read(&rb);
            continue;
        }

        rb_write(&rb, input);

        // Parse the input into arguments
        parseCommand(input, args);

        // no command entered, just skip
        if (args[0] == NULL) {
            continue;
        }

        // Fork a child process to execute the command
        pid = fork();

        if (pid < 0) 
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } 
        else if (pid == 0) 
        {
            // Execute command
            if (execvp(args[0], args) == -1) {
                perror("Execution failed");
            }
            exit(EXIT_FAILURE);
        }
        else 
        {
            wait(NULL);
        }
    }

    return 0;
}
