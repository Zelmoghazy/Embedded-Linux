#!/bin/bash

# List available networks and prompt for selection
SSID=$(nmcli -f SSID dev wifi list | awk 'NR>1' | rofi -dmenu -p "Select WiFi network:")

# Exit if no network selected
if [ -z "$SSID" ]; then
    echo "No network selected. Exiting..."
    exit 1
fi

# Prompt for WiFi password using dmenu
PASSWORD=$(echo "" | dmenu -p "Enter password for $SSID:")

# Connect to the selected WiFi network
nmcli d wifi connect "$SSID" password "$PASSWORD"

# Check the connection status
if [ $? -eq 0 ]; then
    notify-send "Connected to $SSID"
else
    notify-send "Failed to connect to $SSID"
fi
