#!/bin/bash

# Arguments
filename=$0
arg1=$1
arg2=$2
echo "${filename} args: ${arg1}, ${arg1}"

echo "filename: $0"
echo "arg1: $1"
echo "arg2: $2"
echo "number of arguments: $#"
echo "all arguments: $@"
echo "all arguments: $*"
echo "process id: $$"
echo "exit code: $?"

for val in $(seq 1 $#) ; do
    echo $1
    shift
done