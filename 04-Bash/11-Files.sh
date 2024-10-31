#!/bin/bash

# Overwrite the file with new content
echo "This is a new line of text." > test.txt
# Append a line to the file
echo "This line is appended to the file." >> test.txt

# Append file with multiple lines
cat >> test.txt << EOF
This is line 1.
This is line 2.
This is line 3.
EOF

# Append the current date to the file
date >> test.txt

# Redirect Output of an Entire Script to a File
{
    echo "Additional data..."
    df -h  # Disk usage
} >> test.txt  # Append to the file


# Append using tee
echo "This will be appended" | tee -a test.txt
