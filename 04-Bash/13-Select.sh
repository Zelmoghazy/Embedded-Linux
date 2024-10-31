#!/bin/bash

PS3="Please choose an option: "
options=("Option 1" "Option 2" "Option 3" "Quit")

select opt in "${options[@]}"
do
    case $opt in
        "Option 1")
            echo "You chose option 1"
            ;;
        "Option 2")
            echo "You chose option 2"
            ;;
        "Option 3")
            echo "You chose option 3"
            ;;
        "Quit")
            echo "Exiting..."
            break
            ;;
        *) echo "Invalid option";;
    esac
done


#!/bin/bash

PS3="Choose a file to view: "
select file in *; do
    if [[ -n $file ]]; then
        echo "You selected: $file"
        cat "$file"
        break
    else
        echo "Invalid selection"
    fi
done
