#!/bin/bash

echo "Running Internet Speed Test..."

res=$(speedtest-cli --simple) 

echo "Speed Test Results: "
echo "$res"