#!/bin/bash

# Define text color and style variables
RESET='\033[0m'      # Reset all styles

# Text colors
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
BLUE='\033[34m'
MAGENTA='\033[35m'
CYAN='\033[36m'
WHITE='\033[37m'

# Text styles
BOLD='\033[1m'
UNDERLINE='\033[4m'
REVERSED='\033[7m'

# Function to print colored and styled text
print_style() {
    local style="$1"
    local color="$2"
    local text="$3"
    echo -e "${style}${color}${text}${RESET}"
}

# Examples of usage
print_style "$BOLD" "$RED" "This is bold red text"
print_style "$UNDERLINE" "$GREEN" "This is underlined green text"
print_style "$REVERSED" "$BLUE" "This is reversed blue text"
print_style "$BOLD" "$MAGENTA" "This is bold magenta text"
print_style "" "$CYAN" "This is cyan text with no additional style"
print_style "$UNDERLINE" "$YELLOW" "This is underlined yellow text"
print_style "" "$WHITE" "This is white text with no additional style"
