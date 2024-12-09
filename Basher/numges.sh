#!/bin/bash
echo
target=$((RANDOM % 100 + 1))
echo "Guess a number between 1 and 100:"
i=1
while true; do
    read guess
    if ((guess < target)); then
        echo "Too low! Try again:"
        i=$((i+1))
    elif ((guess > target)); then
        echo "Too high! Try again:"
        i=$((i+1))
    else
        echo "Congratulations! You guessed it in $i tries!"
        break
    fi
done
echo