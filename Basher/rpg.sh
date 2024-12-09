#!/bin/bash
# Generate a random password of specified length

generate_password() {
    local length=${1:-12}  # Default to 12 characters if no length specified
    # Use /dev/urandom to generate truly random characters
    tr -dc 'A-Za-z0-9!@#$%^&*()_+' < /dev/urandom | head -c "$length"
    echo  # Add a newline at the end
}

echo "Your random password is: $(generate_password)"