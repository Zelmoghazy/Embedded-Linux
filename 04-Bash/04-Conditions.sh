#!/bin/bash

# Conditions
test $arg1 = $arg2
echo $?

test 1 -eq 1
echo $?

test $arg1 = $arg2 && echo "True" || echo "False"


test 1 -eq 2 && echo "True" || echo "False"



[ $arg1 = $arg2 ] && echo "True" || echo "False"



if [ $arg1 = $arg2 ]; then
    echo "True"
else
    echo "False"
fi



if [ $arg1 = $arg2 ]; then
    echo "True"
elif [ $arg1 = "Hello" ]; then
    echo "Hello"
else
    echo "False"
fi


if [ 1 -eq 1 ] && [ 2 -eq 2 ]; then
    echo "True"
fi


if [[ -z "$string" ]]; then
  echo "String is empty"
elif [[ -n "$string" ]]; then
  echo "String is not empty"
fi