#!/bin/bash

SSID=$(nmcli -f SSID dev wifi list --rescan yes | awk 'NR>1' | rofi -dmenu -p "Select WiFi network:")

if [ -z "$SSID" ]; then
    echo "No network selected. Exiting..."
    exit 1
fi

PASSWORD=$(echo "" | rofi -dmenu -p "Enter password for $SSID:")

nmcli d wifi connect "$SSID" password "$PASSWORD"

if [ $? -eq 0 ]; then
    notify-send "Connected to $SSID"
else
    notify-send "Failed to connect to $SSID"
fi
