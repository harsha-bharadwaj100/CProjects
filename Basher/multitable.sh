#!/bin/bash
# Number to generate table for
echo "Enter a number:"
read number

# Initialize counter
i=1

echo "Multiplication Table for $number:"

# While loop to generate table
while [ $i -le 10 ]; do
    result=$((number * i))
    echo "$number x $i = $result"
    ((i++))
done