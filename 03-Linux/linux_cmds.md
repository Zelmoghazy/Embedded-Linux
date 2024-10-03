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

echo "hello world" | xclip      # pipe output to clipboard
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

echo "alias mygrep='grep -r -n -i -C2'" >> ~/.bashrc        # set alias
source ~/.bashrc
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
cp {src} {dest}
cp -r {src_dir} {dest_dir}
cp -t {dest_dir} {file1} {file2}
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


```bash
grep "{pattern}" {file}

grep -F "{exact}" {file}                     # search for an exact string
grep -r -n {pattern} {directory}             # search recursively in a directory, show line numbers
grep -i {pattern} {file}                     # case insensitive search
grep -E {pattern} {file}                     # use extended regular expression
grep -H -n --color=always {pattern} {file}   # with filename and line number
grep -C 2 "pattern" file.txt                 # show 2 lines before and after
grep -w {pattern} {file}                     # match complete words
grep -v {pattern} {file}                     # get all not matching
grep -m5 {pattern} {file}                    # stop after n matches
grep -I {pattern} {file}                     # suppress binary file matches

grep -r -n -i -C2 "{pattern}" {dir}          # alias this 

```
* Regular Expressions
* Meta characters
    * `^` : Matches the start of a line or string.
    * `$` : Matches the end of a line or string.
    * `.` : Matches any single character except a newline.
    * `[]`: Defines a set of characters, matching any one character within the set.
        * `-` : Specifies a range of characters when used inside square brackets.
        * `^` : match with what is not in range
    * `*` : Matches 0 or more occurrences of the preceding character or group.
    * `()`: Groups expressions and captures the matched text (Extended).
    * `{}`: Specifies the exact number of occurrences of the previous element (Extended)
        * `{n}`   : n times
        * `{n,m}` : n to m times
        * `{n,}`  : n or more times
        * `{,m}`  : m or less times
         
    * `?` : Matches 0 or 1 occurrence of the preceding character or group (Extended)
    * `+` : Matches 1 or more occurrences of the preceding character or group (Extended)
    * `|` : Acts as a logical OR, matching either the expression before or after it (Extended)
    * `\` : Escapes a special character or introduces a special sequence
* shorthand classes
    * `\w` : equivalent to `[a-zA-Z0-9_]`
    * `\s` : stands for space characters or tabs or line breaks
    * `\t` : stands for tabs
    * `\r` : carriage return
    * `\n` : line feed


```
strace {proc}       # tracing system calls by executing a process
```

```
du -sh {dir}                                           # show size of directory
du -h -m --max-depth=2 | sort --numeric-sort --reverse    # List the human-readable sizes of a directory and any subdirectories, up to 2 levels deep
du -ch *.mp4
```

```
sort --numeric-sort --reverse file
sort --ignore-case
sort --unique
```


```
ps aux              # list all running processes
ps --sort size      # sort processes by memory consumption
```

```
ps aux | awk '{print $11}'           # print the command column of ps aux
ps aux | awk '/root/ {print $2}'     # Print the second column of the lines containing "root"   
awk 'NR%3==1' {{path/to/file}}       #  Print every third line starting from the first line
```


file type   User    Group   Other   
d           rwx     rwx     rwx   

```bash
# change mode

chmod u+x {{path/to/file}}                  # add executable permission to user
chmod u+rw {{path/to/file_or_directory}}    # add read and write permission to user
chmod u-rw {{path/to/file_or_directory}}    # remove read and write permission to user

chmod -R u+rw {{path/to/directory}}         # recursively add read and write permission to user
```

```
# change owner

chown {{user}} {{path/to/file_or_directory}}
```

```
watch {command}                         # repeatedly run a command and show results
watch -n 60 {command}                   # run command every 60 seconds
```

```
ctrl + a        # start of line 
ctrl + e        # end of line
ctrl + d        # delete highlighted letter
ctrl + w        # delete word to left of cursor
alt  + d        # delete word to right of cursor
ctrl + k        # delete to the end
ctrl + u        # delete to beginning

ctrl + xx       # jump between saved locations

ctrl + r        # reverse search

ctrl + _        # undo last executed action

Alt+r           # Revert all changes to the current line

ctrl+c          # Capitalise the character under the cursor and move to the end of the current smallword

Alt-Ctrl-e:     #Expand the current line (expand aliases for example or enviroment vars)
 
```

```
_$          #last argument
history     # all previous commands
history | awk '{print $2}'
!!          # execute last command
!122        # execute comman 122 from history

!$: An alias for the last bigword of the previous command.
!^: An alias for the first bigword of the previous command.
!*: An alias for the previous command without the last bigword.
```

## File Compression and Archiving

* TAR (Tape Archive): Combines multiple files into a single archive without compressing them. 
    * It's used for bundling files together, typically in Linux/Unix systems.

* GZIP: A compression tool that reduces the size of individual files or archives. 
    * It is often used with TAR to compress the TAR archive (.tar.gz).

* Use TAR when: You want to bundle multiple files together into one archive without compressing.
* Use GZIP when: You want to compress files for storage or transfer. Often, you’ll combine them (tar + gzip) to archive and compress simultaneously.

```
tar cf {target.tar} {{file1} {file2}
tar tvf {{path/to/source.tar}}          # List the contents of a tar
tar xvf {{path/to/source.tar}}          # extract an archive

tar czf {target.tar.gz} {file1} {file2} # compress in addition

gunzip --list {{file.txt.gz}}   # list
gunzip {{archive.tar.gz}}       # decompresses only resulting in a tar file
tar xvzf {{archive.tar.gz}}     # both decompresses and extracts the files

```

```
{{command}} | sed 's/apple/mango/g'
```