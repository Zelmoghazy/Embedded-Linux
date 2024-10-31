#!/bin/bash

# Arrays
arr=(1 2 3 4 5)
echo ${arr[0]}
echo ${arr[1]}

Fruits=("${Fruits[@]}" "Watermelon")    # Push
Fruits+=('Apple')                       # Also Push
Fruits+=('Orange' 'Peach')                      

Veggies=("carrot" "broccoli" "spinach" "cucumber" "tomato" "bell_pepper" "onion" "potato" "celery" "asparagus")

Fruits=( "${Fruits[@]/Ap*/}" )          # Remove by regex match
unset Fruits[2]                         # Remove one item

Fruits=("${Fruits[@]}")                 # Duplicate
Fruits=("${Fruits[@]}" "${Veggies[@]}") # Concatenate

for i in "${Fruits[@]}"; do
  echo "$i"
done

echo "${Fruits[0]}"           # Element #0
echo "${Fruits[-1]}"          # Last element
echo "${Fruits[@]}"           # All elements, space-separated
echo "${#Fruits[@]}"          # Number of elements
echo "${#Fruits}"             # String length of the 1st element
echo "${#Fruits[3]}"          # String length of the Nth element
echo "${Fruits[@]:3:2}"       # Range (from position 3, length 2)
echo "${!Fruits[@]}"          # Keys of all elements, space-separated