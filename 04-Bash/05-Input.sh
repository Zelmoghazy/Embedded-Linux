#!/bin/bash


read -p "Enter a number: " num

for i in $(seq 1 $num); do
    echo $i
done


# Reading lines

while read -r line; do
  echo "$line"
done <file.txt