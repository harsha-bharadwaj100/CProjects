#!/bin/bash

echo "Enter the number of rows:"
read rows

for ((i=0; i<rows; i++))
do
  for ((j=0; j<=i; j++))
  do
    factorial_i=$(echo "$i" | awk '{for(i=1;i<=$1;i++) s=s*i}END{print s}')
    factorial_j=$(echo "$j" | awk '{for(i=1;i<=$1;i++) s=s*i}END{print s}')
    factorial_ij=$(echo "$((i-j))" | awk '{for(i=1;i<=$1;i++) s=s*i}END{print s}')
    nCr=$((factorial_i / (factorial_j * factorial_ij)))
    echo -n "$nCr "
  done
  echo
done
