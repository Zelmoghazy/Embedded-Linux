 ## File and Directory management

* command type
    * built in shell command
    * executable

* All built in shell commands in bash

```bash
help
```

```bash
type cd
type cat
```     

```bash
ls
ls -l
ls -la      # list all including hidden in long format
ls -lhs     # list with size in human readable format
ls -RS      # list files recursively sorted by size(descending)
ls -lt      # list recently modified
ls -1       # one file per line
ls -d */    # only directories
ls -F
```

```bash
pwd         #print current directory
cd  {path}    #change directory
cd  ..
cd
cd -
cd /

pushd {path}    # switch to path and push it to a stack
popd            # remove top directory from the stack and cd to it
dirs            # display directory stack
```

### External
```
tree
tldr
```

```
mkdir folder1 folder2
mkdir -p folder1/folder2
# create two folders each containing two folders
mkdir -p folder{1,2}/folder{3,4}

```

```bash
touch filename
```

```bash
alias word=command
alias                   # list all aliases
alias word              # view command related to an alias

```

```
echo "Text $PWD $PS1 $SHELL $TERM $PATH $HOSTTYPE"
echo -e #enable special characters
echo $?   #exit status of las executed command
```
```
printenv
```


```
rm 
rm -f # ignore if doesnt exist
rm -i # ask before removing
rm -v # print info
rm -r # remove directories recursively
```


```bash
cat file
cat -n file 
cat -e file             # to check for trailing white space
cat -t file             # to check for tabs
cat file1 file2 > file
cat - > file            # from stdin to file (ctrl+d to exit)

head -n2 file
tail -n2 file

tail -f file            #  output appended data as the file grows;


more file               # like man pages


less file
    /string         # search for a string (press n/N to go to next or previous)
    ?string         # backward search
    v               # open current file in an editor to edit
    q               # exit                         
    -I              # case insensitive search  
```

```
cp src dest
cp -r src_dir dest_dir
cp -t dir file1 file2
```

```
mv src dest
mv --force src dest
mv --interactive src dest
mv --no-clobber src dest
```
```
which exec
whereis exec

```
```
wc --lines {{path/to/file}}
wc --words {{path/to/file}}
wc --bytes {{path/to/file}}
wc --chars {{path/to/file}}
wc --max-line-length {{path/to/file}}
```

```
date +%c
date +%s
date -d @1473305798
```


---


## controls

* Redirection
    * `>`  : redirect stdout
    * `2>` : redirect stderr
    * `<`
* piping 
    * '|'
* wild cards
    * `*` : zero or more characters
    * `?` : single character
    * `[]` : ranges
        * `ls file[1-4].txt`
    * `{}` : brace expansion
        * `echo file{1,2,3,4}.txt`
        * `echo file{1..4}.txt`
    * `!` : negate a pattern
    
stdin -> /proc/self/fd/0
stdout -> /proc/self/fd/1 
stderr -> /proc/self/fd/2

```
echo "hello world"  >  test.txt     # redirect stdout overwriting file
echo "hello world2" >> test.txt     # append stdout to file

echo "alias mygrep='grep -r -n -i -C2'" >> ~/.bashrc


wrong_cmd 2> test.txt               # redirect stderr

ls -l | wc -l                       # pipe output of ls to input of  wc

strace ls |& grep write             # pipe both stdout and stderr

```



* run in background
```
{command} &
```


```
grep "{pattern}" {file}

grep -F "{exact}" {file}                     # search for an exact string
grep -r -n {pattern} {directory}             # search recursively in a directory, show line numbers
grep -E -i {pattern} {file}                  # use extended regular expression, case insensitive
grep -H -n --color=always {pattern} {file}
grep -C 2 "pattern" file.txt                 # show 2 lines before and after

grep -r -n -i -C2 "{pattern}" {dir}          # alias this 

```

```
strace {proc}
```