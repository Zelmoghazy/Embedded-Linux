#!/bin/bash


# set -x # Debug
# set -e # Exit on error
# set -u # Exit on undefined variable






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



selected_color=$(echo -e "red\ngreen\nblue" | rofi -dmenu)
echo $selected_color

choice=$(echo -e "Logout\nShutdown\nReboot" | rofi -dmenu -p "Select an option")
if [ $choice = "Logout" ]; then
    pkill -KILL -u $USER
elif [ $choice = "Shutdown" ]; then
    sudo shutdown -h now
elif [ $choice = "Reboot" ]; then
    sudo reboot
fi
