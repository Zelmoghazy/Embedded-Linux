#!/bin/bash

greet() {
    echo "Hello, $1 $2!"
}

greet "Zeyad" "Elmoghazy"

#--------------------------------------

add_numbers() {
    local num1=$1
    local num2=$2
    return $((num1 + num2))  # Return the sum
}

add_numbers 5 7
sum=$?          # capturing return value
echo "The sum is $sum"

#--------------------------------------

square() {
    echo $(( $1 * $1 ))
}

# Capture function output
result=$(square 4)
echo "The square is $result"

#--------------------------------------

# Default argument
greet() {
    local name=${1:-Guest}  # Default to 'Guest' if no argument is passed
    echo "Hello, $name!"
}

# Call without an argument (uses default)
greet

# Call with an argument
greet "Alice"

#--------------------------------------

# Function to print elements of an array
print_array() {
    local arr=("$@")  # Capture all passed arguments as an array
    for element in "${arr[@]}"; do
        echo "$element"
    done
}

# Define an array and pass it to the function
my_array=("Apple" "Banana" "Cherry")
print_array "${my_array[@]}"


#--------------------------------------

# Function that uses command substitution
get_current_date() {
    local date_now=$(date +"%Y-%m-%d")
    echo "Today's date is $date_now"
}

# Call the function
get_current_date

#--------------------------------------


# An anonymous function (subshell)
(
    echo "This is a subshell (anonymous function)"
    echo "You can execute commands here"
)
