#!/bin/bash

# Variables
var="Hello"
var2="$var World"
var3='$var World'
var4=Hello

echo $var
echo $var2
echo $var3
echo $var4

echo "${var}World"

cmd=$(date)

echo "${cmd}"
#--------------------------------------------------------------------------------------

# Global variable
greeting="Hello, World!"

function say_hello() {
    local name="John"       # Local variable
    
    echo "$greeting"        # Can access global variable
    echo "Hello, $name"     # Local variable only accessible within this function
}

say_hello  # Output: Hello, World! Hello, John

# Trying to access the local variable outside the function
echo "Outside function, name is: $name"  # Output: name is not found (empty)

# Accessing global variable outside function
echo "Outside function, greeting is: $greeting"  # Output: Hello, World!


#--------------------------------------------------------------------------------------
readonly pi=3.14159
echo "Value of pi: $pi"  # Output: 3.14159

# Attempting to modify pi
pi=3.14

#--------------------------------------------------------------------------------------


my_var="Hello, World!"

# Exporting the variable so it's available in child processes
export my_var

# This child script or command will have access to the exported variable
bash -c 'echo "Inside subshell: $my_var"'  # Output: Inside subshell: Hello, World!

# If we did not export 'my_var', it would not be accessible in the subshell.

#--------------------------------------------------------------------------------------