#!/bin/bash

# Declare an associative array
declare -A myMap

# Add key-value pairs
myMap["apple"]="red"
myMap["banana"]="yellow"
myMap["grape"]="purple"
myMap["lemon"]="yellow"

# Access a value by key
echo "The color of an apple is ${myMap["apple"]}"

# Loop over keys and values
echo "All fruits and their colors:"
for fruit in "${!myMap[@]}"; do
    echo "$fruit is ${myMap[$fruit]}"
done

# Check if a key exists
key="banana"
if [[ -v myMap[$key] ]]; then
    echo "$key is in the map with color ${myMap[$key]}"
else
    echo "$key is not in the map"
fi

# Remove a key-value pair
unset myMap["grape"]
echo "After removing 'grape':"
for fruit in "${!myMap[@]}"; do
    echo "$fruit is ${myMap[$fruit]}"
done
