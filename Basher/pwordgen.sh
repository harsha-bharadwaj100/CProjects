#!/bin/bash
echo "Enter the length of the password:"
read length
characters="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()"
password=$(head /dev/urandom | tr -dc "$characters" | head -c "$length")
echo "Generated Password: $password"