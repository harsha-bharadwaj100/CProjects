#!/bin/bash

# Take input from the user
echo "Enter a string:"
read string

# Initialize the vowel counter
vowel_count=0

# Convert the string to lowercase to handle both upper and lower case vowels
string=$(echo $string | tr '[:upper:]' '[:lower:]')

# Loop through each character of the string
for (( i=0; i<${#string}; i++ ))
do
  char="${string:$i:1}"
  
  # Check if the character is a vowel
  if [[ "$char" == "a" || "$char" == "e" || "$char" == "i" || "$char" == "o" || "$char" == "u" ]]
  then
    ((vowel_count++))
  fi
done

# Output the result
echo "Number of vowels in the string: $vowel_count"
