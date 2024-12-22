## Virtual Terminals

*  Move between virtual terminals

```
ctrl + alt + f1-7
```

## All pseudo terminals

```
ls /dev/pts/*
```

```
tty     # which term am I
```

```
screen -S session_name      # start a new named screen session
screen -r session_name      # reattach to an open screen

tmux
```

## Shell
* sh : bourne SHell (written by Stephen Bourne)
* bash : Bourne Again SHell

```
echo $0             # check what shell you are currently using
echo $SHELL         # the default shell.
```

* Login Shell startup commands

```
~/.profile  # User specific

# which internally calls 
~/.bashrc

```

```
# Execute commands from a file in the current shell(no fork).

source {{path/to/file}}
. {{path/to/file}}

source ~/.bashrc        # force a bashrc execution in current shell

```

* Command Categories
    * built in shell command {`cd`, `pwd`, etc.}
    * Executable called by the shell program
    * Alias to another command
    * Shell functions


* All built in shell commands in bash

```bash
help        # get builtin commands list
help cd     # get help of a builtin command
```
* Identify the category of the command

```bash
type cd
type cat
```

* To get more information
```
man <command>             # read manual pages
manpath
man <n> <command>         # sections
* sections :
    * 1 - commands
    * 2 - system calls
    * 3 - C library functions
    * 4 - special filenames 
    * 5 - file formats  for linux files
    * 6 - games and things like screen savers
    * 7 - word processing packages & Misc
    * 8 - System adminstration commands

whatis <command>          # search man page titles by keywords
apropos <keyword>         # search man pages by keywords same as man -k <keyword>

info <command>            # read info pages

tldr <cmd>                # common uses for commands
```     

* bash shortcuts

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

alt+r           # Revert all changes to the current line

alt+c          # Capitalise the character under the cursor and move to the end of the current smallword

alt+ctrl+e     # Expand the current line (expand aliases for example or enviroment vars)
 
```

```
_$                           # last argument
history                      # all previous commands
history | awk '{print $2}'
!!                           # execute last command
!122                         # execute command 122 from history
!rm                          # execute last rm command witht the previous args
!<command>!*                 # run command with all arguments from last command
!<command>!$                 # run command with only last argument from the last command

!$         # An alias for the last bigword of the previous command.
!^         # An alias for the first bigword of the previous command.
!*         # An alias for the previous command without the last bigword.
```

```
!$	        # Expand last parameter of most recent command
!*	        # Expand all parameters of most recent command
!-n	        # Expand nth most recent command
!n	        # Expand nth command in history
!<command>	# Expand most recent invocation of command <command>

!!	                # Execute last command again
!!:s/<FROM>/<TO>/	# Replace first occurrence of <FROM> to <TO> in most recent command
!!:gs/<FROM>/<TO>/	# Replace all occurrences of <FROM> to <TO> in most recent command
!$:t	            # Expand only basename from last parameter of most recent command
!$:h	            # Expand only directory from last parameter of most recent command


!!:n	            Expand only nth token from most recent command (command is 0; first argument is 1)
!^	                Expand first argument from most recent command
!$	                Expand last token from most recent command
!!:n-m	            Expand range of tokens from most recent command
!!:n-$	            Expand nth token to last from most recent command
```


```
script logfile.log  # Start recording terminal session in a given file
exit                # Stop recording

# Append to an existing file:
script -a logfile.log

# Execute quietly without start and done messages:
script -q logfile.log

# put timestamp infront of each command
script -t logfile.log

# flush after each command
script -f logfile.log

```
* Enviroment Variables

```
# Display the names and values of shell variables:
set

# Display key-value pairs of all environment variables:
printenv

# Display the value of a specific variable:
printenv HOME
```

```bash
# Set a new environment variable
export VARIABLE=value

# Remove an environment variable
export -n VARIABLE

# Mark a shell function for export
export -f FUNCTION_NAME

# Append something to the PATH variable
export PATH=$PATH:path/to/append

```

## Commands

### Sequential commands

* Sequential commands just run after each other, they have independent input and output

```
<first_command>;<second_command>;<third_command>
```

### Conditional commands

1- Oring (`||`) : Second command will only execute if the first returns failure

```
cat file.txt || echo "File Not found!"
```

2- Anding (`&&`) : Second command will only execute if the first returns successfully

```
mkdir dir1 && cd dir1
```

### Command Loops

```
for file in *.txt do mv -v $file $file.old done
```
### Command argument expansion
* `~` : path of user home folder
* `${}` : evaluate shell or enviroment variables
* `$(())` : evaluate an arithmetic expansion
* `{}`: brace expansion repeat for every element in set

### Command Argument Quoting
* `""` : protect strings, from command substitution, from arithmetic expansion but doesnt stop variable retrieval
* `''` : protect everything even variable retrieval
* `` or  `$()` : evaluate commands inside commands/strings


---

## controls

* Redirection
    * `>`, `1>` : redirect stdout
    * `2>` : redirect stderr
    * `<`
* piping 
    * `|` : mechanism in linux kernel that is used to enable one process to send information to the other processes
    * `tee` : Read from stdin and pipe to stdout and files (or commands)
    * `yes` : commonly used to answer yes to every prompt by install commands (`yes | sudo apt-get install {{program}}`)
* wild cards
    * `*` : zero or more characters
    * `?` : single character
    * `[]` : ranges
        * `ls file[1-4].txt`
        * `ls file[1-37-9].txt`
        * `ls file[abcd].txt`
    * `{}` : brace expansion
        * `echo file{1,2,3,4}.txt`
        * `echo file{1..4}.txt`
    * `!` : negate a pattern
    
stdin -> /proc/self/fd/0
stdout -> /proc/self/fd/1 
stderr -> /proc/self/fd/2

```
command >file1 2>file2              # output to file1 and error to file2

command >file 2>&1                  # output both to a file and overwrite
command &>file

command >>file 2>>&1                # output both to a file and append
command &>>file

command <file                       # command input is read from a file

comman1 | command2 | command3       # pipe output of each command to the input of another

echo "hello world"  >  test.txt     # redirect stdout overwriting file
echo "hello world2" >> test.txt     # append stdout to file

cat file1 file2 > combined.txt

echo "alias mygrep='grep -r -n -i -C2'" >> ~/.bashrc

make 2> log                         # errors only go to a file
wrong_cmd 2>> test.txt              # redirect stderr and append

wc -l < file                        # count number of lines in a file

ls -l | wc -l                       # pipe output of ls to input of wc
cat file | grep "error"

strace ls |& grep "write"           +# pipe both stdout and stderr

# Print stdin to the terminal, and also pipe it into another program for further processing:
echo "example" | tee /dev/tty | xargs printf "[%s]"

echo "hello world" | xclip      # pipe output to clipboard

```

## File and Directory management

```
# - : for short name , -- : for long name
ls -a
ls --all
```
```bash
ls          # list everything in current directory excluding hidden files
ls -l       # list in long format list (file type, permissions, # of hard links, owners, file size, last modify time, file name)

# file names starting with a dot are hidden files
ls -la      # list all including hidden in long format

ls -lhs     # list with size in human readable format
ls -RS      # list files recursively sorted by size(descending)
ls -lt      # list recently modified
ls -1       # one file per line
ls -d */    # only directories
ls -F

ls -i       # show inode number
```

### Navigation commands

```bash
pwd            # print current(working) directory

cd {path}      # change directory to another path
cd ..          # Go up to the parent of the current directory
cd ~           # ~ : home directory
cd             # home directory of current user
cd -           # Go to the previously chosen directory
cd /           # Go to the root directory:

pushd {path}    # switch to path and push it to a stack
popd            # remove top directory from the stack and cd to it
dirs            # display directory stack

tree            # list as a tree of files
```

### Handling File and Directories

```
mkdir folder1 folder2          # create directories
mkdir -p folder1/folder2       # create nested directories

# create two folders each containing two folders
mkdir -p folder{1,2}/folder{3,4}

# Create directories with specific permissions:
mkdir -m rwxrw-r-- path/to/directory1 path/to/directory2 ...

```

```bash
touch filename
>>filename       # create an empty file (if it exists it will update it timestamp)
```

```
rm 
rm -f # ignore if doesnt exist
rm -i # ask before removing
rm -v # print info
rm -r # remove directories recursively
```

```
cp {src} {dest}
cp -r {src_dir} {dest_dir}
cp -t {dest_dir} {file1} {file2}
```

```
# used to move or rename
mv src dest
mv -i src dest        # Prompt for confirmation before overwriting existing files
mv -f src dest        # Do not prompt for confirmation before overwriting existing files  
mv -n src dest        # Do not overwrite existing files 
```

```bash
alias word=command
alias                   # list all aliases
alias word              # view command related to an alias

# set a permanent alias directly from the terminal
echo "alias mygrep='grep -r -n -i -C2'" >> ~/.bashrc        # set alias
source ~/.bashrc
```


## Text Handling

### Displaying text

```bash
echo "Text $PWD $PS1 $SHELL $TERM $PATH $HOSTTYPE"

echo -e         # enable special characters
echo $?         # exit status of last executed command
```
```
printf "$PATH\n"
```

```bash
cat file                # send requested file to stdout
cat -n file             # number output lines
cat -e file             # to check for trailing white space an other nonprinting chars
cat -t file             # to check for tabs
cat file1 file2 > file  # concat outputs to a single file
cat * > file            # all files in the folder are merged into one file
cat - > file            # from stdin to file (ctrl+d to exit)
```

```bash
head -n 2 file           # show the first 2 lines of the file
tail -n 2 file           # show the last 2 lines of the file

tail -f file             # Follow appended data as the file grows
```

```bash
more file           # display file in a page by page fashion like man pages

less file
    /string         # search for a string (press n/N to go to next or previous)
    ?string         # backward search
    v               # open current file in an editor to edit
    q               # exit                         
    -I              # case insensitive search  
    
ls -la | less       # very useful as last command in a pipe
```

```
which exec
whereis exec
```


```
date +%c
date +%s
date -d @1473305798

cal
cal 2011
ncal
```

```
bc      # basic calculator
```

```
sleep 1     #delay for 1 s
```



```
/dev/zero       # input device generating infinite stream of zeroes
/dev/random     # input device to generate random byte, it may block
/dev/urandom    # generate quasi-random bytes, doesnt block
/dev/full       # simulate a full file for testing
```

* run in background
```
{command} &
```


## Searching Text

```bash
grep "{pattern}" {file}

grep -i {pattern} {file(s)}                     # case insensitive search
grep -n {pattern} {file(s)}                     # show line numbers in matched pattern
grep -v {pattern} {file(s)}                     # get all not matching
grep -c {pattern} {file(s)}                     # get the count of matches
grep -r -n {pattern} {directory}                # search recursively in a directory, show line numbers
grep -w {pattern} {file(s)}                     # match complete words
grep -m5 {pattern} {file(s)}                    # stop after n matches
grep -F "{exact}" {file(s)}                     # search for an exact string
grep -E {pattern} {file(s)}                     # use extended regular expression
grep -H -n --color=always {pattern} {file(s)}   # with filename and line number
grep -C 2 "pattern" file(s).txt                 # show 2 lines before and after
grep -I {pattern} {file(s)}                     # suppress binary file matches

grep -r -n -i -C2 "{pattern}" {dir}             # alias this 

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
du -sh {dir}                                              # show size of directory
du -h -m --max-depth=2 | sort --numeric-sort --reverse    # List the human-readable sizes of a directory and any subdirectories, up to 2 levels deep
du -ch *.mp4
```

```bash
sort {file} # sort lines in a file alphabetically

sort -n {file}     # numeric sort
sort -n -r {file}     # sort in reverse
sort -f {file}        # ignore case
sort -u {file}        # sort a file preserving only unique lines  
sort -b               # ignore leading blanks

# Sort file by the 3rd field of each line numerically, using ":" as a field separator:
sort -t=: -k=3n {file}

sort < file > sorted_file
```

```
# uniq does not detect repeated lines unless they are adjacent, we need to sort them first.

sort {{path/to/file}} | uniq -c             # number of occurrences of each line along with that line
sort {{path/to/file}} | uniq -d             # Display only duplicate lines
sort {{path/to/file}} | uniq -c | sort -nr  # Display number of occurrences of each line, sorted by the most frequent:

```

```
wc -l {{path/to/file}}       # Count all lines in a file
wc -w {{path/to/file}}       # Count all words in a file
wc -c {{path/to/file}}       # Count all bytes in a file **
wc -m {{path/to/file}}       # Count all characters in a file
wc -L {{path/to/file}}       # Count the length of the longest liqne in number of characters
```

```
# spell checker
spell file.txt
```

```
diff {old_file} {new_file}                          # Compare files
diff -y --color=always {old_file} {new_file}        # showing the differences side by side
diff -u --color=always {old_file} {new_file}        # showing the differences in unified format (as used by git diff)
diff -w {old_file} {new_file}                       # Ignore white spaces

diff -a -u -N  {old_file} {new_file} > {diff.patch} # create a patch file 
```

```
# Apply a patch to a specific file:
patch {{path/to/file}} < {{patch.diff}}

# Patch a file writing the result to a different file:
patch {{path/to/input_file}} -o {{path/to/output_file}} < {{patch.diff}}
```

```
ps                  # list current running process on terminal
ps aux              # list all running processes
ps --sort size      # sort processes by memory consumption
watch -n 1 "ps auxf"
```

```
ps aux | awk '{print $11}'                  # print the command column of ps aux
ps aux | awk '/root/ {print $2}'            # Print the second column of the lines containing "root"   
ls -la | awk '{print $9 ":" $5}'            # print the size of all files in current directory
awk 'NR%3==1' {{path/to/file}}              #  Print every third line starting from the first line
echo "input" | awk '{print $1"string"}'     # append string to stdout
```


```
{{command}} | sed 's/apple/mango/g'

echo ${PATH} | sed 's/:/\n/g'
```


file type           User    Group   Other   
-------------------------------------------
d(directory)        rwx     rwx     rwx   
l(symbolic link)    rwx     rwx     rwx   
b(block)            rwx     rwx     rwx   
c(char)             rwx     rwx     rwx   
p(pipe)             rwx     rwx     rwx   
s(socket)           rwx     rwx     rwx   

* minimum directory size = 4k

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
cut {file} -c 2              # select two characters from each line of current file
ls -l | cut -d ' ' -f 1-4    # selects words from 1-4 delimited by space
```

```
hexdump -C  main                    # dump executable in canonical mode (hex+ascii)
hexdump -C -n 64  main              # interpret 64 bytes only from beginning
hexdump -C -s 1024 -n 64  main      # interpret 64 bytes only from 1024

```

```
file {file}         # description of file type
```

```
stat {file}         # properties about a specific file such as size, permissions, creation and access dates
```

### System Information

```
hostname        # get the machine name

uname           # Print kernel name
uname -m -p     # Print system architecture and processor information
uname -s -r -v  # Print kernel name, kernel release and kernel version
uname -n        # Print system hostname
uname -a        # Print all available system information
```

```
free -h # Display memory in human-readable units:
```

```
df  #  Display all filesystems and their disk usage using 512-byte units:
```

```
uptime              # get system uptime
uptime --pretty     # Show only the amount of time the system has been booted for:
```

```
lscpu       # Display information about the CPU architecture.
lspci       # List all PCI devices.
lsusb       # Display information about USB buses and devices connected to them.
lsblk       # Lists information about devices
```

```
cat /etc/hostname
whoami
cat /etc/lsb-release
cat /etc/os-release
uname -a
cat /proc/meminfo

```

```
id # Display current user and group identity.
```

```
dmesg       # Write the kernel messages to stdout.
journalctl  # Query the systemd journal.
```

```
Find files by extension:
   find {{root_path}} -name '{{*.ext}}'
   
   
 - Find empty files (0 byte) or directories and delete them verbosely:
   find {{root_path}} -type {{f|d}} -empty -delete -print
```

```
ls /proc/
ls /sys/
ls /dev/
```

```
top         # dynamic realtime information about running processes
```


```
ps -aux     # all with tty, except session leaders, effective user id or name,
ps -elf
ps -o pid,ppid,cmd
ps -lt
ps -auTH

```

```
cat /sys/class/power_supply/BAT0/capacity       # battery percentage
```

### Process
```
pidof 
pstree
jobs
```

```
pkill
kill
```

```
crontab -e

 - Sample job which runs at 10:00 every day (* means any value):
   0 10 * * * {{command_to_execute}}

 - Sample crontab entry, which runs a command every 10 minutes:
   */10 * * * * {{command_to_execute}}
```

### Networking
```
ping google.com
ping {host}
ping -c {count} {host}  # ping certain number of times
ping -i {host}          # ping every second
```

```
## Get IP address of current machine
ip address | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1'
```

```
# get global ip address
curl ifconfig.me
```

```
 - List all ports:
   netstat --all

 - List all listening ports:
   netstat --listening

 - List listening TCP ports:
   netstat --tcp

 - Display PID and program names:
   netstat --program
```

```
 - Connect to a remote server:
   ssh {{username}}@{{remote_host}}
```

```
scp {{path/to/local_file}} {{remote_host}}:{{path/to/remote_file}}
```
```
tcpdump
```

```
arp
```

```
 - Start a listener on the specified TCP port and send a file into it:
   nc -l -p {{port}} < {{filename}}

 - Connect to a target listener on the specified port and receive a file from it:
   nc {{host}} {{port}} > {{received_filename}}

 - Scan the open TCP ports of a specified host:
   nc -v -z -w {{timeout_in_seconds}} {{host}} {{start_port}}-{{end_port}}

 - Send an HTTP GET request:
   echo -e "GET / HTTP/1.1\nHost: {{host}}\n\n" | nc {{host}} 80
```

```
 - View network settings of an Ethernet adapter:
   ifconfig eth0

 - Display details of all interfaces, including disabled interfaces:
   ifconfig -a

 - Disable eth0 interface:
   ifconfig eth0 down

 - Enable eth0 interface:
   ifconfig eth0 up

 - Assign IP address to eth0 interface:
   ifconfig eth0 {{ip_address}}

```


```
 - Download the contents of a URL to a file (named "foo" in this case):
   wget {{https://example.com/foo}}

 - Download the contents of a URL to a file (named "bar" in this case):
   wget --output-document {{bar}} {{https://example.com/foo}}

 - Download a single web page and all its resources with 3-second intervals between requests (scripts, stylesheets, images, etc.):
   wget --page-requisites --convert-links --wait=3 {{https://example.com/somepage.html}}

 - Download all listed files within a directory and its sub-directories (does not download embedded page elements):
   wget --mirror --no-parent {{https://example.com/somepath/}}

 - Limit the download speed and the number of connection retries:
   wget --limit-rate={{300k}} --tries={{100}} {{https://example.com/somepath/}}

 - Download a file from an HTTP server using Basic Auth (also works for FTP):
   wget --user={{username}} --password={{password}} {{https://example.com}}

 - Continue an incomplete download:
   wget --continue {{https://example.com}}

 - Download all URLs stored in a text file to a specific directory:
   wget --directory-prefix {{path/to/directory}} --input-file {{URLs.txt}}

```

```
 - Make an HTTP GET request and dump the contents in stdout:
   curl {{https://example.com}}

 - Make an HTTP GET request, fo[L]low any 3xx redirects, and [D]ump the reply headers and contents to stdout:
   curl --location --dump-header - {{https://example.com}}

 - Download a file, saving the [O]utput under the filename indicated by the URL:
   curl --remote-name {{https://example.com/filename.zip}}

 - Send form-encoded [d]ata (POST request of type application/x-www-form-urlencoded). Use --data @file_name or --data @'-' to read from stdin:
   curl -X POST --data {{'name=bob'}} {{http://example.com/form}}

 - Send a request with an extra header, using a custom HTTP method and over a pro[x]y (such as BurpSuite), ignoring insecure self-signed certificates:
   curl -k --proxy {{http://127.0.0.1:8080}} --header {{'Authorization: Bearer token'}} --request {{GET|PUT|POST|DELETE|PATCH|...}} {{https://example.com}}

 - Send data in JSON format, specifying the appropriate Content-Type [H]eader:
   curl --data {{'{"name":"bob"}'}} --header {{'Content-Type: application/json'}} {{http://example.com/users/1234}}

 - Pass client certificate and key for a resource, skipping certificate validation:
   curl --cert {{client.pem}} --key {{key.pem}} --insecure {{https://example.com}}

 - Resolve a hostname to a custom IP address, with [v]erbose output (similar to editing the /etc/hosts file for custom DNS resolution):
   curl --verbose --resolve {{example.com}}:{{80}}:{{127.0.0.1}} {{http://example.com}}

```

## Package management

```
 - Install a package:
   dpkg -i {{path/to/file.deb}}

 - Remove a package:
   dpkg -r {{package}}

 - List installed packages:
   dpkg -l {{pattern}}

 - List a package's contents:
   dpkg -L {{package}}

 - List contents of a local package file:
   dpkg -c {{path/to/file.deb}}

 - Find out which package owns a file:
   dpkg -S {{path/to/file}}
```

## Tracking

```
 - Start tracing a specific [p]rocess by its PID:
   strace -p {{pid}}
   
strace -e openat df -h     #  Trace a [p]rocess and filt[e]r output by system call:
strace -c ls                #  Count time, calls, and errors for each system call and report a summary on program exit

 - Show the [T]ime spent in every system call:
   strace -p {{pid}} -T

```

```
# Print (trace) library calls of a program binary:
ltrace ./program
```

```
# Display shared library dependencies of a binary:
ldd path/to/binary
```

## Symbolic Link

```
# always use absolute paths for the file to link to when creating symbolic links

# To create a symlink:
ln -s <source-location> <symlink-location>

# Create a hard link to a file:
ln /path/to/file path/to/hardlink
```

```
# Read from `/dev/urandom`, 2*512 Bytes, and put it into `/tmp/test.txt`.
# Note: each iteration reads 512 bytes (the selected block size).
dd if=/dev/urandom of=/tmp/test.txt count=2 bs=512
```

```
# Calculate the parent directory of a given path:
dirname path/to/file_or_directory
```

```
# Start an [i]nteractive session with the standard math [l]ibrary enabled:
   bc --interactive --mathlib

# Calculate a sine/cosine/arctangent/natural logarithm/exponential function using `mathlib`:
echo 's|c|a|l|e(1)' | bc --mathlib
```

```
pkill -KILL -u $USER
sudo shutdown -h now
sudo reboot now
```

```
# get process id
ps ax | grep Main
```


```
# How many threads in process
watch -n 1 "ps huH p <pid> | wc -l"
```

```
# tree view of processes and their children
watch -n 1 "ps auxf"
```

```
# run terminator with a command
terminator -e 'btop; exec bash'
```

```
echo "Hello world" | xclip -sel clip
```

```
xclip -o -sel clip
```




```
# Replace all occurrences of a character in a file, and print the result:
tr find_character replace_character < path/to/file

# Replace all occurrences of a character from another command's output:
echo text | tr find_character replace_character

# Map each character of the first set to the corresponding character of the second set:
tr 'abcd' 'jkmn' < path/to/file

# Delete all occurrences of the specified set of characters from the input:
tr -d 'input_characters' < path/to/file

# Compress a series of identical characters to a single character:
tr -s 'input_characters' < path/to/file

# Translate the contents of a file to upper-case:
tr "[:lower:]" "[:upper:]" < path/to/file

# Strip out non-printable characters from a file:
tr -cd "[:print:]" < path/to/file

```

```
/dev/null is the null device it takes any input you want and throws it away. It can be used to suppress any output.

command > /dev/null 2>&1 &
```


```
# Get WiFi status (enabled / disabled)
nmcli radio wifi

# Enable / Disable WiFi
nmcli radio wifi <on|off>

# Show all available WiFi access points
nmcli dev wifi list

# Connect to a wireless access point - Parameters:
#       <wiface> -- the name of your wireless interface
#       <ssid> -- the SSID of the access point
#       <pass> -- the WiFi password
nmcli d wifi connect <ssid> password <pass> iface <wiface>

# Show WiFi password and QR code
nmcli dev wifi show

# Show all available connections
nmcli con

# Get WiFi status (enabled / disabled)
nmcli radio wifi
```

```
# Type a message, with a 500ms delay for each letter:
xdotool type --delay 500 "Hello world"

# Press the enter key:
xdotool key KP_Enter
```

```
# To see running processes:
systemctl

# To check the status of a service:
systemctl status foo.service

# To start/restart/stop a service:
systemctl start/restart/stop foo.service

# To reload a service's configuration:
systemctl reload foo.service

# To edit a service's configuration:
systemctl edit foo.service

# To reload systemd manager configuration:
systemctl daemon-reload

# To enable a service to startup on boot:
systemctl enable foo.service

# To disable a service to startup on boot:
systemctl disable foo.service

systemctl list-dependencies
```


```
# To see log items from the most recent boot:
journalctl -b

# To to see only kernal messages, add -b for at the most recent boot:
journalctl -k

# To get the log entries for a service since boot:
journalctl -b -u foo.service

journalctl --lines 20 --follow
```

```
## Get first 10 errors only (very useful)
make 2>&1 >/dev/null | grep "error" | head
```

--- 

```
# Generate a new SSH key pair (using RSA algorithm, 4096 bits for strong security)
ssh-keygen -t rsa -b 4096

# When prompted:
# 1. Enter a file location (or press Enter for default ~/.ssh/id_rsa)
# 2. Enter a passphrase (recommended for security) or press Enter twice for no passphrase

# Display your public key
cat ~/.ssh/id_rsa.pub

# Replace username and server_address with your values
ssh-copy-id username@server_address

## graphical apps
ssh -X hostname
```


```

 - Show current host name:
   hostname

 - Show the network address of the host name:
   hostname -i

 - Show all network addresses of the host:
   hostname -I

 - Show the FQDN (Fully Qualified Domain Name):
   hostname --fqdn

 - Set current host name:
   hostname new_hostname
```

## File transfer

```
 - Copy a local file to a remote host:
   scp path/to/local_file remote_host:path/to/remote_file

 - Use a specific port when connecting to the remote host:
   scp -P port path/to/local_file remote_host:path/to/remote_file

 - Copy a file from a remote host to a local directory:
   scp remote_host:path/to/remote_file path/to/local_directory

 - Recursively copy the contents of a directory from a remote host to a local directory:
   scp -r remote_host:path/to/remote_directory path/to/local_directory

 - Copy a file between two remote hosts transferring through the local host:
   scp -3 host1:path/to/remote_file host2:path/to/remote_directory

 - Use a specific username when connecting to the remote host:
   scp path/to/local_file remote_username@remote_host:path/to/remote_directory

 - Use a specific SSH private key for authentication with the remote host:
   scp -i ~/.ssh/private_key path/to/local_file remote_host:path/to/remote_file

 - Use a specific proxy when connecting to the remote host:
   scp -J proxy_username@proxy_host path/to/local_file remote_host:path/to/remote_file
```


---
```
Debian package manager.
Some subcommands such as deb have their own usage documentation.
For equivalent commands in other package managers

 - Install a package:
   dpkg -i path/to/file.deb

 - Remove a package:
   dpkg -r package

 - List installed packages:
   dpkg -l pattern

 - List a package's contents:
   dpkg -L package

 - List contents of a local package file:
   dpkg -c path/to/file.deb

 - Find out which package owns a file:
   dpkg -S path/to/file

 - Purge an installed or already removed package, including configuration:
   dpkg -P package
```
