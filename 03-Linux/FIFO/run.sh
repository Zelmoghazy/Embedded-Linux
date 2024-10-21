mkfifo my_fifo
gcc writer.c -o writer
gcc reader.c -o reader