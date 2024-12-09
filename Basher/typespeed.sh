#!/bin/bash

sentence="The quick brown fox jumps over the lazy dog."
echo "Type the following sentence as quickly as you can:"
echo "\"$sentence\""
start_time=$(date +%s)

read user_input
end_time=$(date +%s)

if [[ "$user_input" == "$sentence" ]]; then
    time_taken=$((end_time - start_time))
    echo "Great! You took $time_taken seconds."
else
    echo "Oops! You mistyped the sentence."
fi
