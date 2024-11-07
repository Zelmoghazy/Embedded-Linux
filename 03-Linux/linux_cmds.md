 ## File and Directory management

* command type
    * built in shell command
    * executable

* All built in shell commands in bash


```
# - : for short name , -- : for long name
ls -a
ls --al
```

```bash
help
```

```bash
type cd
type cat
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
```

```bash
pwd             # print current(working) directory
cd  {path}      # change directory to another path
cd  ..          # Go up to the parent of the current directory
cd  ~           # ~ : home directory
cd              # home directory of current user
cd -            # Go to the previously chosen directory
cd /            # Go to the root directory:

pushd {path}    # switch to path and push it to a stack
popd            # remove top directory from the stack and cd to it
dirs            # display directory stack
```

### External
```
tree            # list a tree of files
tldr

echo "hello world" | xclip      # pipe output to clipboard
```

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
# used to move or rename
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
watch -n 1 "ps auxf"
```

```
ps aux | awk '{print $11}'                  # print the command column of ps aux
ps aux | awk '/root/ {print $2}'            # Print the second column of the lines containing "root"   
ls -la | awk '{print $9 ":" $5}'            # print the size of all files in current directory
awk 'NR%3==1' {{path/to/file}}              #  Print every third line starting from the first line
echo "input" | awk '{print $1"string"}'     # append string to stdout
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

Alt+c          # Capitalise the character under the cursor and move to the end of the current smallword

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

uname           # Print kernel name
uname -m -p     # Print system architecture and processor information:
uname -s -r -v  # Print kernel name, kernel release and kernel version
uname -n        # Print system hostname
uname -a        # - Print all available system information:
```


```
free -h # Display memory in human-readable units:
```

```

df  #  Display all filesystems and their disk usage using 512-byte units:
```

```
uptime --pretty # Show only the amount of time the system has been booted for:
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
sudo reboot
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
#Execute commands from a file in the current shell(no fork).
source {{path/to/file}}

```


```
# Set a new environment variable:
export VARIABLE=value

# Remove an environment variable:
export -n VARIABLE

# Mark a shell function for export:
export -f FUNCTION_NAME

# Append something to the PATH variable:
export PATH=$PATH:path/to/append

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
```

```
## Get first 10 errors only (very useful)
make 2>&1 >/dev/null | grep "error" | head
```