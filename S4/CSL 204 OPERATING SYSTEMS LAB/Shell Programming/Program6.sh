#!/bin/bash
read -p "Number 1: " a
read -p "Number 2: " b
read -p "Number 3: " c
if [ $a -gt $b ]
then
	if [ $a -gt $c ]
	then
		echo "$a is larger"
	else
		echo "$c is larger"
	fi

else		
	if [ $b -gt $c ]
	then
		echo "$b is larger"
	else
		echo "$c is larger"
	fi
fi
