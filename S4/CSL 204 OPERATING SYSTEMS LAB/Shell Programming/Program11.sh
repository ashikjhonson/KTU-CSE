#!/bin/bash

read -p "Enter a number: " num

if [ $num -ge 0 ]
then
	echo "Positive"
else
	echo "Negative"
fi
