#!/bin/bash

# Define short options; "c:" means -c requires a value
OPTIONS="a,b,c:"

# Parse options
PARSED=$(getopt "$OPTIONS" "$@")
if [[ $? -ne 0 ]]; then
  echo "Failed to parse options." >&2
  exit 1
fi

# Set the parsed options
eval set -- "$PARSED"

# Loop through options
while true; do
  case "$1" in
    -a)
      echo "Option -a selected"
      shift
      ;;
    -b)
      echo "Option -b selected"
      shift
      ;;
    -c)
      echo "Option -c selected with argument $2"
      shift 2
      ;;
    --)
      shift
      break
      ;;
    *)
      echo "Invalid option $1" >&2
      exit 1
      ;;
  esac
done

# Remaining arguments
echo "Remaining arguments: $@"

