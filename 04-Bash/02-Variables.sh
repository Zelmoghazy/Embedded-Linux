#!/bin/bash

# Variables
var="Hello"
var2="$var World"
var3='$var World'
var4=Hello

echo $var
echo $var2
echo $var3
echo $var4

echo "${var}World"

cmd=$(date)

echo "${cmd}"