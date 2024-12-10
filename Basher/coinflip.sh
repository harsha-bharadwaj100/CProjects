#!/bin/bash
# Simple coin flip game

flip=$((RANDOM % 2))
echo $flip
echo "🪙 Flipping a coin..."
sleep 1

if [ $flip -eq 0 ]; then
    echo "Heads!"
else
    echo "Tails!"
fi