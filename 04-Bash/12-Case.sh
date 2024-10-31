#!/bin/bash

fruit="APPLE"

case $fruit in
    "apple"|"APPLE")
        echo "You selected apple."
        ;;
    "banana"|"BANANA")
        echo "You selected banana."
        ;;
    "orange")
        echo "You selected orange."
        ;;
    *)
        echo "Unknown fruit."
        ;;
esac

number=2

case $number in
    1)
        echo "One"
        ;;
    2)
        echo "Two"
        ;;
    3)
        echo "Three"
        ;;
    *)
        echo "Number is out of range."
        ;;
esac
