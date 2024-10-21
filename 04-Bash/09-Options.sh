#!/bin/bash

set -e            # Exit on error
set -x            # Print each command before execution (debugging)
set -u            # Exit on unset variables
set -o pipefail   # Make pipelines fail if any command fails
set -v            # Print shell input lines as they are read (verbose)
set -n            # Read commands but don't execute (syntax check)
set -f            # Disable pathname expansion (globbing)
set -b            # Notify of background job termination immediately
set -C            # Prevent overwriting files with '>'
set -o history    # Enable command history
set -o ignoreeof  # Prevent exit with Ctrl-D
set -o noglob     # Disable pathname expansion (same as -f)
set -o noclobber  # Prevent overwriting files (same as -C)
set -o notify     # Notify immediately of job status changes
set -T            # Enable function tracing
set -o vi         # Use vi-style command-line editing
set -o emacs      # Use emacs-style command-line editing (default)

# Disable options (example of turning them off)
set +e            # Disable 'exit on error'
set +x            # Stop printing commands before execution
set +u            # Allow unset variables
set +v            # Stop printing input lines as they are read
set +n            # Execute commands (disable no-execution mode)
