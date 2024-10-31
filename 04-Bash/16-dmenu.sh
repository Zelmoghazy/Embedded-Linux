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
