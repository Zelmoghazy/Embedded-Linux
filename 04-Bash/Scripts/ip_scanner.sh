#!/bin/bash

# Define the IP range base
base_ip="192.168"

# Loop through the second octet from 1 to 100
for i in {1..100}; do
    # Construct the full IP address
    ip="$base_ip.1.$i"
    
    # Ping the IP address and check for 0% packet loss
    ping -c 1 -W 1 $ip | grep " 0% packet loss" > /dev/null
    
    if [ $? -eq 0 ]; then
        echo "$ip is connected"
    else
        echo "$ip is not connected"
    fi
done
