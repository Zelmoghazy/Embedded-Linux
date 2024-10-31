#!/bin/bash

# Import utils.sh using source
source ./19-1-Modularity.sh # or you can use . ./utils.sh

# Call the function defined in utils.sh
greet

# Access the variable defined in utils.sh
echo "My favorite color is $FAVORITE_COLOR"
 