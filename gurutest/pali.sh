#!/bin/bash

echo "Enter a number:"
read number

original_number=$number
reversed_number=0

while [ $number -gt 0 ]
do
  digit=$((number % 10))
  reversed_number=$((reversed_number * 10 + digit))
  number=$((number / 10))
done

if [ $original_number -eq $reversed_number ]
then
  echo "The number is a palindrome."
else
  echo "The number is not a palindrome."
fi
