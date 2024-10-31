#!/bin/bash

# Path to the file containing the snippets
SNIPPET_FILE="$HOME/snippets.txt"

# Check if the snippet file exists
if [[ ! -f "$SNIPPET_FILE" ]]; then
    echo "Snippet file not found!"
    exit 1
fi

# Use rofi in dmenu mode to select a snippet
CHOSEN=$(cat "$SNIPPET_FILE" | rofi -dmenu -p "Choose a snippet:")

# If a snippet is chosen, use xdotool to paste it
if [[ -n "$CHOSEN" ]]; then
    # Use xdotool to type the chosen snippet
    xdotool type --delay 10 "$CHOSEN"
fi

