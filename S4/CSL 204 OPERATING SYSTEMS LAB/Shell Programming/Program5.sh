#!/bin/bash

read -p "Enter number: " NUM

if [[ `expr $NUM % 2` == 0 ]]
then
	echo  "Even number"
else
	echo  "Odd number"
fi

