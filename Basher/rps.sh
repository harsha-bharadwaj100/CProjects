#!/bin/bash
# Rock Paper Scissors Game

choices=("Rock" "Paper" "Scissors")
computer_choice=$((RANDOM % 3))

echo "🎮 Rock Paper Scissors Game"
echo "Choose: 0 for Rock, 1 for Paper, 2 for Scissors"
read -p "Your choice (0-2): " player_choice

echo "Computer chose: ${choices[$computer_choice]}"
echo "You chose: ${choices[$player_choice]}"

# Simplified winning logic
if [ "$player_choice" = "$computer_choice" ]; then
    echo "🤝 It's a tie!"
elif [ "$player_choice" = 0 ] && [ "$computer_choice" = 2 ]; then
    echo "🏆 You win! Rock crushes Scissors"
elif [ "$player_choice" = 1 ] && [ "$computer_choice" = 0 ]; then
    echo "🏆 You win! Paper covers Rock"
elif [ "$player_choice" = 2 ] && [ "$computer_choice" = 1 ]; then
    echo "🏆 You win! Scissors cut Paper"
else
    echo "😢 Computer wins!"
fi