#!/bin/bash
# Simple password strength checker
echo "Enter your password"
read password
echo $password

password="$1"
length=${#password}

echo $length
echo "Checking password strength..."

if [ $length -lt 6 ]; then
    echo "🔴 Weak: Too short"
elif [ $length -lt 10 ]; then
    echo "🟠 Medium: Consider making it longer"
else
    echo "🟢 Strong: Good password!"
fi

