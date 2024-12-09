#!/bin/bash
display_header() {
    echo "🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐"
    echo "   WEBSITE AVAILABILITY CHECKER   "
    echo "🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐🌐"
}

# Check if websites are provided as arguments
if [ $# -eq 0 ]; then
    display_header
    echo "❓ Usage: $0 <website1> [website2] [website3] ..."
    echo "Example: $0 google.com github.com stackoverflow.com"
    exit 1
fi

# Display header
display_header

# Check each provided website
for site in "$@"; do
    echo "Checking $site..."
    if ping -c 4 "$site" &> /dev/null; then
        echo "✅ $site is UP! 🟢"
    else
        echo "❌ $site is DOWN! 🔴"
    fi
    echo "------------------------"
done

echo "🌐 Check Complete 🌐"