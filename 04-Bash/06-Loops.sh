#!/bin/bash


# Loops

for i in {1..10}; do
    echo $i
done

lst=$(ls)
for i in ${lst}; do
    echo $i
done

for i in ${lst}; do
    wc -l $i
done


while [ $num -gt 0 ]; do
    echo $num
    num=$((num-1))
done

until [ $num -gt 10 ]; do
    echo $num
    num=$((num+1))
done