#!/bin/bash

read -p "Enter a number: " num

fact=1

if [ $num -ge 0 ]
then 
	for((i=2;i<=num;i++))
	do
		fact=`expr $((fact * i))`
	done
	echo "$fact"
else
	echo "Negative number!"
fi




