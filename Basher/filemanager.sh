#!/bin/bash
echo "Enter filename to create:"
read filename
touch $filename
echo "$filename created."

echo "Enter filename to rename:"
read oldname
echo "Enter new name:"
read newname
mv $oldname $newname
echo "File renamed to $newname."

echo "Enter filename to delete:"
read delname
rm $delname
echo "$delname deleted."

