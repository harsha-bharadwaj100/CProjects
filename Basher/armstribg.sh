echo "Enter a number to check if it's an Armstrong number:"
read number
original=$number
sum=0
digits=${#number}

while [ $number -gt 0 ]
do
    digit=$((number % 10))
    sum=$((sum + digit**digits))
    number=$((number / 10))
done

if [ $sum -eq $original ]; then
    echo "$original is an Armstrong number!"
else
    echo "$original is not an Armstrong number."
fi