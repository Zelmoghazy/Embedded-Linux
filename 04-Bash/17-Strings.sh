#!/bin/bash

str="Hello, World!"
echo $str

str=$(ls -1 | wc -l)
echo $str

# Concatenating Strings
str1="Hello"
str2="World"
result="$str1, $str2!"
echo $result

# String Length
str="Hello"
echo "Length of string ${str} is : ${#str}"

# Extracting a Substring
str="Hello, World!"
echo ${str:7:5}     # 5 characters from the 7th char

## Replacing a Substring
str="Hello, Bash!"
echo ${str/Bash/World}  

# Checking if a String Contains a Substring
str="Hello, Bash!"
if [[ $str == *"Bash"* ]]; then
  echo "String contains 'Bash'"
fi

#  Splitting a String
str="apple,banana,orange"
IFS=',' read -r -a fruits <<< "$str"
echo "${fruits[0]}"  
echo "${fruits[1]}"  

# Converting to Upper/Lowercase
str="hello"
echo "${str^^}"  
echo "${str,,}"  

# ${foo%suffix}	    Remove suffix
# ${foo#prefix}	    Remove prefix
# ${foo%%suffix}	Remove long suffix
# ${foo/%suffix}	Remove long suffix
# ${foo##prefix}	Remove long prefix
# ${foo/#prefix}	Remove long prefix
# ${foo/from/to}	Replace first match
# ${foo//from/to}	Replace all
# ${foo/%from/to}	Replace suffix
# ${foo/#from/to}	Replace prefix

str="/path/to/foo.cpp"
echo "${str%.cpp}"    # /path/to/foo    (Remove suffix)
echo "${str%.cpp}.o"  # /path/to/foo.o
echo "${str%/*}"      # /path/to

echo "${str##*.}"     # cpp (extension)
echo "${str##*/}"     # foo.cpp (basepath)

echo "${str#*/}"      # path/to/foo.cpp  (Remove prefix)
echo "${str##*/}"     # foo.cpp (Remove long prefix)

echo "${str/foo/bar}" # /path/to/bar.cpp